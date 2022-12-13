clear all
close all
clc
%% Simulation Parameters
%Moduluation method QPSK

N = 9600; % Number of data bits

%fft Size
nfft = 64;
n_fft = 64;
n_plt = 6;
data_len = n_fft-n_plt;
%Size of cycle prefix extension
n_cpe = 16;

snr = 40; % in dB

%number of channel taps.

n_taps = 8;

ch_est_method = 'LS';
% ch_est_method = 'none';

%% Data generation

data_bits = randsrc(N,1,[[0,1];[0.5,0.5]]);

%% Binary stream to symbols

cons_data = reshape(data_bits,2,length(data_bits)/2)';
cons_sym_id = bi2de(cons_data);
%% symbol modulation

mod_data = qammod(cons_sym_id,4);

%% Use IFFT to move to time domain
% pad input signal to appropriate length
fft_rem = mod(data_len-mod(length(mod_data),data_len),data_len);
X_padded = [mod_data;zeros(fft_rem,1)];
X_blocks = reshape(X_padded,data_len,length(X_padded)/data_len);
% x = ifft(X_blocks);

%Add cyclic prefix entension and shift from parallel to serial
x_cpe = [x(end-n_cpe+1:end,:);x];
x_s = x_cpe(:);

%% Apply fading channel
g = exp(-(0:n_taps-1));
g = g/norm(g);
% x_s_fading = conv(x_s,g,'same');

x_s_fading = zeros(80,75);
for ii = 1:75
    x_s_fading(:,ii) = conv(x_cpe(:,ii), g, 'same');
    
end
x_s =  x_s_fading(:);

%% Add AWGN
% Calculate data power
data_pwr =1 ;% mean(abs(x_s.^2));

% Add noise to the channel
noise_pwr = data_pwr/10^(snr/10);
noise = normrnd(0,sqrt(noise_pwr/2),size(x_s))+normrnd(0,sqrt(noise_pwr/2),size(x_s))*1i;
noise = zeros(size(noise));
% Measure SNR
snr_meas = 10*log10(mean(abs(x_s.^2))/mean(abs(noise.^2)));
x_s_noise_fading = x_s + noise;

%% Use FFT to move to frequency domain
% Remove cyclic prefix extension and shift from serial to parallel
x_p = reshape(x_s_noise_fading,nfft+n_cpe,length(x_s_noise_fading)/(nfft+n_cpe));
x_p_cpr = x_p(n_cpe+1:end,:);

% Move to frequency domain
% X_hat_blocks = fft(x_p_cpr);
for i = 1:75
    X_hat_blocks(:,i) = fft(x_p_cpr(:,i));
end
%% Channel estimation

G = X_hat_blocks(:,1)./X_blocks(:,1);
X_hat_blocks1 = X_hat_blocks./repmat(G,1,size(X_hat_blocks,2));
%% Symbol demodulation
% remove fft padding
X_hat = X_hat_blocks1(:);
X_hat = X_hat(1:end-fft_rem);

scatterplot(X_hat,4)
grid on

dem_symbol = qamdemod(X_hat,4);

sym_rem = 0;

rec_syms_cons = de2bi(dem_symbol);
rec_im_bin = reshape(rec_syms_cons',numel(rec_syms_cons),1);
rec_im_bin = rec_im_bin(1:end-sym_rem);
ber = sum(abs(rec_im_bin-data_bits))/length(data_bits);








