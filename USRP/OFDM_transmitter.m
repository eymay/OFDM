% No. of Pilots: 4
% Cylic Extension: 25%(16)
% close all
% clear all
% clc
%%
% Generating and coding data


t_data=randi([0,1],9600,1)';
x=1;
si=1; %for BER rows

%Size of cycle prefix extension
n_cpe = 16;
Nfft = 64;
n_taps = 3;
with_cp = 80;
symbol_number = length(t_data)/120;

g = exp(-(0:n_taps-1));
g = g/norm(g);

snr = 15;

%%
for d=1:symbol_number
    data=t_data(x:x+119);
    x=x+120;
    k=3;
    n=6;
    s1=size(data,2);  % Size of input matrix
    j=s1/k;
    
    
    %% Binary stream to symbols
    
    cons_data = reshape(data,2,length(data)/2)';
    cons_sym_id(:,d) = bi2de(cons_data);
    %% symbol modulation
    
    mod_data = qammod(cons_sym_id(:,d),4);
    %% Pilot insertion
    
    
    pilt=1+1i;
    nofpits=4;
    k=1;
    
    mod_data = [pilt;mod_data(1:15,1);pilt;mod_data(16:30,1); ...
        pilt;mod_data(31:45,1); ...
        pilt;mod_data(46:60,1)];
    
    %% ÝFFT and CP adding
    x_ifft = ifft(mod_data);
    
    x_cpe(:,d) = [x_ifft(end-n_cpe+1:end,:);x_ifft];
%     x_cpe=awgn(x_cpe,snr,'measured');      % simülasyonlar için gürültü eklendi sonra silinecek
end

barker = comm.BarkerCode('SamplesPerFrame',80);
seq = barker();

% N0 = 1/(10^(snr/10));
% n = (randn(1,length(seq))+1i*randn(1,length(seq)));
% 
% seq = seq + sqrt(N0/2)*n'; 
x_cpe = [seq, seq, x_cpe(:,1:40) seq x_cpe(:,41:end)]; % preamble location 1 2 43

x_transmitted = reshape(x_cpe,[1,size(x_cpe,1)*size(x_cpe,2)]);

y = x_transmitted.';
















