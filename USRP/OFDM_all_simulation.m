% No. of Pilots: 4
% Cylic Extension: 25%(16)
close all
clear
clc
%%
% Generating and coding data
t_data=randi([0,1],9600,1)';

x=1;
%Size of cycle prefix extension
n_cpe = 16;
Nfft = 64;
n_taps = 3;
with_cp = 80;
symbol_number = 80;

g = exp(-(0:n_taps-1));
g = g/norm(g);
   
    for d=1:symbol_number
        data=t_data(x:x+119);
        x=x+120;
        k=3;
        n=6;
        s1=size(data,2);  % Size of input matrix
        j=s1/k;
        
        
        %% Binary stream to symbols
        
        cons_data = reshape(data,2,length(data)/2)';
        cons_sym_id(:,d) = bi2de(cons_data);
        %% symbol modulation
        
        mod_data = qammod(cons_sym_id(:,d),4);
        %% Pilot insertion
        
        pilt=1+1i;
        nofpits=4;
        k=1;
        
        mod_data = [pilt;mod_data(1:15,1);pilt;mod_data(16:30,1); ...
            pilt;mod_data(31:45,1); ...
            pilt;mod_data(46:60,1)];
        
        %% ÝFFT and CP adding
        x_ifft = ifft(mod_data);
        
        x_cpe(:,d) = [x_ifft(end-n_cpe+1:end,:);x_ifft];
        %     x_cpe=awgn(x_cpe,snr,'measured');      % simülasyonlar için gürültü eklendi sonra silinecek
    end
    
    barker = comm.BarkerCode('SamplesPerFrame',80);
    seq = barker();
    
    % N0 = 1/(10^(snr/10));
    % n = (randn(1,length(seq))+1i*randn(1,length(seq)));
    %
    % seq = seq + sqrt(N0/2)*n';
    x_cpe = [seq, seq, x_cpe(:,1:40) seq x_cpe(:,41:80)]; % preamble location 1 2 43
    
    x_transmitted = reshape(x_cpe,[1,size(x_cpe,1)*size(x_cpe,2)]);
    
    
    
    
    %% Generate OFDM Waveform
    % Burada kendi transmitter mýzdan aldýðýmýz datalarla gürültü ekleyip
    % random offset belirleyerek coarse time senkronizasyonu yapýyoruz
    
    SNR = 5:5:20;
for SNRindx = 1:length(SNR)
    y = zeros(length(x_transmitted.'),1);
    y = x_transmitted.';
    % Add random offset
    offset = randi([0 1e2]) % simülasyon için
    y = [zeros(offset,1);y];
    
    Fs =1e6;
    %% Schmidl and Cox: Coarse Packet Detection
    L = 80; % Short sync field length
    m = L; % Distance between fields
    N = 150; % Autocorrelation samples
    M = zeros(N,1);
%     r_fading_awgn(:,SNRindx) = zeros(length(x_transmitted.')+100,1); 
    
    %     r_fading = conv(y, g, 'same');
    r_fading_awgn(:,SNRindx) = awgn(y,SNR(SNRindx),'measured');
    
    pfOffset = comm.PhaseFrequencyOffset('SampleRate',Fs,...
        'FrequencyOffset',2e3);
    r_CFO(:,SNRindx) = pfOffset(r_fading_awgn(:,SNRindx));
    
    % Determine timing metric
    M = zeros(N,1);
        
    for k=1:N                   %% Auto corr döngüsü
        P(k) = r_CFO(k:k+m,(SNRindx))' * r_CFO(k+L:k+m+L,(SNRindx));
        a = abs(y(k+L:k+m+L));
        R = a'*a;
        M(k) = abs(P(k))^2/(R^2);
    end
    % Plot
    figure
%     subplot(length(SNR),1,SNRindx);
    stem(M(:,SNRindx));
    hold on;
    stem(offset+1,M(offset+1),'r*'); hold off;
    grid on;xlabel('k');ylabel('M');
    legend('Autocorrelation','True Start');
    title(['SNR: ',num2str(SNR(SNRindx)),'dB']);
    
    
    starting_point_array = find(0.95<M);
    starting_point = starting_point_array(1)
    freqEst(SNRindx) = Fs/L*(angle(P(starting_point))/(2*pi));
    
    nn = 0: length(r_CFO(:,SNRindx))-1;
    r_compansated(:,SNRindx) = r_CFO(:,SNRindx).*exp(-1i*2*pi*freqEst.*nn'/Fs);
    
    for k=starting_point-10:starting_point+10                %% Fine time senk
        P_fine_corr_max(k) = max(xcorr(r_compansated(k:k+1*m-1,(SNRindx)), [seq]));
        
    end
    [~,idx] = max(P_fine_corr_max) %Fine time index bulundu
    
    % [aa,bb] = xcorr(r_compansated(k:k+2*m), [seq;seq])
    % plot(abs(aa(bb>=0)))
    
    
    
    
    %% Fine freq senk
    for ii=1:N                   %% Auto corr döngüsü
        P_fine_freq(ii) = r_compansated(ii+idx:ii+m+idx,SNRindx)' * r_compansated(ii+idx+42*L:ii+idx+42*L+m,SNRindx);
        
    end
    
    
    freqEst_fine = Fs/L*(angle(P_fine_freq(idx))/(2*pi));
    
    nn = 0: length(r_compansated(:,SNRindx))-1;
    r_compansated(:,SNRindx) = r_compansated(:,SNRindx).*exp(-1i*2*pi*freqEst_fine.*nn'/Fs);
    
    
    rx(:,SNRindx) = r_compansated(idx:end,SNRindx);
    
 
    rx_parallel(:,:,SNRindx) = reshape(rx(1:end),80,83);
    rx_parallel_preamble_removed(:,:,SNRindx) = [rx_parallel(:,3:42,SNRindx) rx_parallel(:,44:end,SNRindx)];
    % rx_parallel = rx_parallel(:,83);
    
    for d=1:80
        %               Receiver
        %% Removing CP and FFT
        
        %     x_p_cpr = ofdm_sig(n_cpe+1:end,:);
        x_p_cpr = rx_parallel_preamble_removed(n_cpe+1:end,d,SNRindx);
        
        X_ffted = fft(x_p_cpr);
        
        %% Channel estimation
        pilot_loc = 1:16:60;
        ls_channel = X_ffted(pilot_loc,1)./pilt;
        
        H_interpolated = interpolate(ls_channel',pilot_loc,Nfft,'spline');
        
        X_equ(:,d) = X_ffted.*conj(H_interpolated')./abs(H_interpolated').^2;
        % X_equ = X_ffted
        %% Demodulation
        
        dem_symbol(:,d) = qamdemod(X_equ(:,d),4);
        
        sym_rem = 0;
        
        dem_symbol_pilots_removed(:,d) = [dem_symbol(2:16,d); dem_symbol(18:32,d); dem_symbol(34:48,d); dem_symbol(50:64,d)];
        
        ber(d,SNRindx) = 1-sum(dem_symbol_pilots_removed(:,d) == cons_sym_id(:,d))/length(dem_symbol_pilots_removed(:,d));
        
        
        
    end
    ber_av(SNRindx) = sum(ber)/d;
end



function [H_interpolated] = interpolate(H,pilot_loc,Nfft,method)
% Input: H = Channel estimate using pilot sequence
% pilot_loc = Location of pilot sequence
% Nfft = FFT size
% method = ’linear’/’spline’
% Output: H_interpolated = interpolated channel
if pilot_loc(1)>1
    slope = (H(2)-H_est(1))/(pilot_loc(2)-pilot_loc(1));
    H = [H(1)-slope*(pilot_loc(1)-1) H]; pilot_loc = [1 pilot_loc];
end
if pilot_loc(end) <Nfft
    slope = (H(end)-H(end-1))/(pilot_loc(end)-pilot_loc(end-1));
    H = [H H(end)+slope*(Nfft-pilot_loc(end))];
    pilot_loc = [pilot_loc Nfft];
end
if lower(method(1))=='l', H_interpolated=interp1(pilot_loc,H,[1:Nfft]);
else H_interpolated = interp1(pilot_loc,H,[1:Nfft],'spline');
end
end


