% usrp den sonra rx datasý iþlenbmeye baþlanacak
barker = comm.BarkerCode('SamplesPerFrame',80);
seq = barker();

Fs =1e6;
datax2 = datax(:,4042)
%% Schmidl and Cox: Coarse Packet Detection
L = 80; % Short sync field length
m = L; % Distance between fields
N = 150; % Autocorrelation samples
M = zeros(N,1);
SNR = 10;
for SNRindx = 1:length(SNR)
%     r_fading = conv(y, g, 'same');
%     r_fading_awgn = awgn(r_fading,SNR(SNRindx),'measured');
    
%     pfOffset = comm.PhaseFrequencyOffset('SampleRate',Fs,...
%         'FrequencyOffset',2e3);
%     r_CFO = pfOffset(r_fading_awgn);
    
    % Determine timing metric
    for k=1:N                   %% Auto corr döngüsü
        P(k) = data(k:k+m)' * data(k+L:k+m+L);
        a = abs(datax(k+L:k+m+L));
        R = a'*a;
        M(k) = abs(P(k))^2/(R^2);
    end
    % Plot
    subplot(length(SNR),1,SNRindx);
    stem(M);
%     hold on; 
%     stem(offset+1,M(offset+1),'r*'); hold off;
    grid on;xlabel('k');ylabel('M');
%     legend('Autocorrelation','True Start');
    title(['SNR: ',num2str(SNR(SNRindx)),'dB']);
end

starting_point_array = find(0.79<M);
starting_point = starting_point_array(1)
freqEst = Fs/L*(angle(P(starting_point))/(2*pi));

nn = 0: length(data)-1;
r_compansated = data.*exp(-1i*2*pi*freqEst.*nn'/Fs);

 for k=starting_point-10:starting_point+10                %% Fine time senk
        P_fine_corr_max(k) = max(xcorr(r_compansated(k:k+1*m-1), [seq]));
        
 end
    [~,idx] = max(P_fine_corr_max) %Fine time index bulundu
 
% [aa,bb] = xcorr(r_compansated(k:k+2*m), [seq;seq])
% plot(abs(aa(bb>=0)))




%% Fine freq senk
for ii=1:N                   %% Auto corr döngüsü
    P_fine_freq(ii) = r_compansated(ii+idx:ii+m+idx)' * r_compansated(ii+idx+42*L:ii+idx+42*L+m);
    
end


freqEst_fine = Fs/L*(angle(P_fine_freq(idx))/(2*pi));

nn = 0: length(r_compansated)-1;
r_compansated = r_compansated.*exp(-1i*2*pi*freqEst_fine.*nn'/Fs);


rx = r_compansated(idx:end);
rx_parallel = reshape(data(2:end,1),80,83);
rx_parallel_preamble_removed = [rx_parallel(:,3:42) rx_parallel(:,44:end)];
% rx_parallel = rx_parallel(:,83);


for d=1:80 
%               Receiver
    %% Removing CP and FFT
    
    %     x_p_cpr = ofdm_sig(n_cpe+1:end,:);
    x_p_cpr = rx_parallel_preamble_removed(n_cpe+1:end,d);
    
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
    
    ber(d) = 1-sum(dem_symbol_pilots_removed(:,d) == cons_sym_id(:,d))/length(dem_symbol_pilots_removed(:,d));
            
     

end
ber_av(SNRindx) = sum(ber)/d;


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