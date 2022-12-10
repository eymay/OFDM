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

cons_data = reshape(im_bin_padded,mod_order,length(im_bin_padded)/mod_order)';
cons_sym_id = bin2dec(cons_data);







