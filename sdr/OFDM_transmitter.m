clear all
close all
clc
%% Simulation Parameters
%Moduluation method QPSK

N = 9600; % Number of data bits

%fft Size
nfft = 64;
n_fft = 64;

%Size of cycle prefix extension
n_cpe = 16;

snr = 20; % in dB

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
fft_rem = mod(n_fft-mod(length(mod_data),n_fft),n_fft);
X_padded = [mod_data;zeros(fft_rem,1)];
X_blocks = reshape(X_padded,nfft,length(X_padded)/nfft);
x = ifft(X_blocks);

%Add cyclic prefix entension and shift from parallel to serial
x_cpe = [x(end-n_cpe+1:end,:);x];
x_s = x_cpe(:);