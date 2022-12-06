close all;
clear;
clc;

N = 10^6;

data_bits = randsrc(1,N,[[0,1];[0.5,0.5]]);

S1 = data_bits(1:2:end);
S2 = data_bits(2:2:end);

qpsk_sig = ((S1==0).*(S2==0)*exp(1i*pi/4) ...
            +(S1==0).*(S2==1)*exp(1i*3*pi/4)  ...
            +(S1==1).*(S2==0)*exp(1i*5*pi/4)  ...
            +(S1==1).*(S2==1)*exp(1i*7*pi/4));
        

scatterplot(qpsk_sig,4);
grid on
