
%% Generate OFDM Waveform
% Burada kendi transmitter mýzdan aldýðýmýz datalarla gürültü ekleyip
% random offset belirleyerek coarse time senkronizasyonu yapýyoruz

OFDM_transmitter
% genOFDMPacket

% Add random offset
offset = randi([0 1e2]) % simülasyon için
y = [zeros(offset,1);y];

Fs =1e6;
%% Schmidl and Cox: Coarse Packet Detection
L = 80; % Short sync field length
m = L; % Distance between fields
N = 150; % Autocorrelation samples
M = zeros(N,1);
SNR = 10;
for SNRindx = 1:length(SNR)
    r_fading = conv(y, g, 'same');
    r_fading_awgn = awgn(r_fading,SNR(SNRindx),'measured');
    
    pfOffset = comm.PhaseFrequencyOffset('SampleRate',Fs,...
        'FrequencyOffset',2e3);
    r_CFO = pfOffset(r_fading_awgn);
    
    % Determine timing metric
    for k=1:N                   %% Auto corr döngüsü
        P(k) = r_CFO(k:k+m)' * r_CFO(k+L:k+m+L);
        a = abs(y(k+L:k+m+L));
        R = a'*a;
        M(k) = abs(P(k))^2/(R^2);
    end
    % Plot
    subplot(length(SNR),1,SNRindx);
    stem(M);
    hold on; 
    stem(offset+1,M(offset+1),'r*'); hold off;
    grid on;xlabel('k');ylabel('M');
    legend('Autocorrelation','True Start');
    title(['SNR: ',num2str(SNR(SNRindx)),'dB']);
end

starting_point_array = find(0.79<M);
starting_point = starting_point_array(1)
freqEst = Fs/L*(angle(P(starting_point))/(2*pi));

nn = 0: length(r_CFO)-1;
r_compansated = r_CFO.*exp(-1i*2*pi*freqEst.*nn'/Fs);

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

