clear
close all
clc
%
% % Generation of a simple OFDM signal
%  N=256; % FFT size
%  CP_size=1/4; % CP ratio
%  used_subc_indices=35:1:N-35; % used subcarriers
%  symbols=2*(randn(1,N)>0)-1; % BPSK symbol generation
%  to_ifft=zeros(1,N);
%  to_ifft(used_subc_indices)=symbols(used_subc_indices);
%  time=ifft(to_ifft);
%  time_cp=[time(end-N*CP_size+1:end) time]; % adding CP
%
%  clf; subplot(2,2,[1,2])
%  plot(10*log10(abs(time_cp).^2))
%  hold on
% %  plot(10*log10(abs(time_cp(1:64)).?^2),'r')
%  title('(a) An OFDM time signal')
%  xlabel('Time sample index')
%  ylabel('Power (dB)')
%  subplot(2,2,3)
%  pwelch(time_cp)
%  title('(b) OFDM spectrum (only one symbol)')

% -------- Multiple Symbols --------------
num_OFDM_symbols=1000; % Number of OFDM symbols to be generated
frame=[];
N=256;
CP_size=1/4;
for ii=1:num_OFDM_symbols
    symbols=2*(randn(1,N)>0)-1;
    used_subc_indices=25:1:256-25;
    to_ifft=zeros(1,N);
    to_ifft(used_subc_indices)=symbols(used_subc_indices);
    time=ifft(to_ifft);
    time_cp=[time(end-N*CP_size+1:end) time]; % CP removal
    frame=[frame time_cp]; % Concatenation of generated symbols
end
subplot(2,2,4)
pwelch(frame)
title('(c) OFDM spectrum (multiple symbols)')