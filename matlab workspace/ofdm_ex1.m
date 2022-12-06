close all;
clear;
clc;

bps = 2;    % Bits per symbol
M = 2^bps;  % QPSK
nFFT = 200; % Number of FFT bits

txsymbols = randi([0 M-1],nFFT,1);
txgrid = qammod(txsymbols,M);




txout = ifft(txgrid,nFFT);
stem(1:nFFT,real(txout))

scatterplot(txgrid,bps);


rx_in = fft(txout,200);

res = txgrid-rx_in;



