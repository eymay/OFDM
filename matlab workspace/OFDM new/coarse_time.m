
%% Generate OFDM Waveform
% OFDM_transmitter
genOFDMPacket
% Add random offset
offset = randi([0 1e2]); % sim�lasyon i�in
y = [zeros(offset,1);y];


%% Schmidl and Cox: Coarse Packet Detection
L = 16; % Short sync field length
m = L; % Distance between fields
N = 300; % Autocorrelation samples
M = zeros(N,1);
SNR = 30;
for SNRindx = 1:length(SNR)
r = awgn(y,SNR(SNRindx),'measured');
% Determine timing metric
for k=1:N                   %% Auto corr d�ng�s�
P = r(k:k+m)' * r(k+L:k+m+L);
a = abs(y(k+L:k+m+L));
R = a'*a;
M(k) = abs(P)^2/(R^2);
end
% Plot
subplot(length(SNR),1,SNRindx);stem(M);
hold on; stem(offset+1,M(offset+1),'r*'); hold off;
grid on;xlabel('k');ylabel('M');
legend('Autocorrelation�,�True Start');
title(['SNR: ',num2str(SNR(SNRindx)),'dB']);
end