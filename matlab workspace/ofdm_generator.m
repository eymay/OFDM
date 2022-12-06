close all;
clear;
clc;

M = 4;          % Modulation level
m = log2(M);    % Bits per symbol
N = 400;        % Number of symnbol
N_size = N/2;
data_bits=randsrc(1,N,[[0,1];[0.5,0.5]]);

S1 = data_bits(1:2:end);        % two streams
S2 = data_bits(2:2:end);
B(1:2,:) =[S1;S2]; 
qpsk_sig = sqrt(2)*((S1==0).*(S2==0)*(exp(1i*pi/4)) ...
          + (S1==0).*(S2==1)*(exp(3*1i*pi/4)) ... 
          + (S1==1).*(S2==1)*(exp(5*1i*pi/4)) ...
          + (S1==1).*(S2==0)*(exp(7*1i*pi/4))); 
      
a = qpsk_sig';
txout = ifft(a,N_size);

h = sqrt(0.5*((randn(length(a),1)).^2+(randn(length(a),1)).^2));
n(1:length(a),1) = (randn(length(a),1)+1i*randn(length(a),1));
N0 = 1/(10^(20/10));

rx(1:length(a),1) = txout.*h + sqrt(N0/2)*n(1:length(a),1);   % rayleig and awgn added signal    
rx_eq = rx.*conj(h);
rx_fft = fft(rx_eq,length(a));



scatterplot(a,2)
grid on
hold on
scatterplot(txout,2)
scatterplot(rx_fft,2)




