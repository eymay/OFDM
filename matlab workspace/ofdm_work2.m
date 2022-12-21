% No. of Pilots: 4
% Cylic Extension: 25%(16)
close all
clear all
clc
%%
% Generating and coding data
t_data=randi([0,1],9600,1)';
x=1;
si=1; %for BER rows

%Size of cycle prefix extension
n_cpe = 16;
Nfft = 64;
n_taps = 3;

g = exp(-(0:n_taps-1));
g = g/norm(g);

snr = 30;

%%
for d=1:80;
    data=t_data(x:x+119);
    x=x+120;
    k=3;
    n=6;
    s1=size(data,2);  % Size of input matrix
    j=s1/k;
    
    
    %% Binary stream to symbols
    
    cons_data = reshape(data,2,length(data)/2)';
    cons_sym_id = bi2de(cons_data);
    %% symbol modulation
    
    mod_data = qammod(cons_sym_id,4);
    %% Pilot insertion
    
    
    pilt=1+1i;
    nofpits=4;
    k=1;
    
    mod_data = [pilt;mod_data(1:15,1);pilt;mod_data(16:30,1); ...
        pilt;mod_data(31:45,1); ...
        pilt;mod_data(46:60,1)];
    
    %% ÝFFT and CP adding
    x_ifft = ifft(mod_data);
    
    x_cpe = [x_ifft(end-n_cpe+1:end,:);x_ifft];
    
    %% Fading channel
    
    x_s_fading = conv(x_cpe, g, 'same');
    
%         x_s_fading=awgn(x_cpe,snr,'measured');
    
    
    %%
    %               Receiver
    %% Removing CP and FFT
    
    %     x_p_cpr = ofdm_sig(n_cpe+1:end,:);
    x_p_cpr = x_s_fading(n_cpe+1:end,:);
    
    X_ffted = fft(x_p_cpr);
    
    %% Channel estimation
    pilot_loc = 1:16:60;
    ls_channel = X_ffted(pilot_loc,1)./pilt;
    
    H_interpolated = interpolate(ls_channel',pilot_loc,Nfft,'spline');
    
    X_equ(:,d) = X_ffted.*conj(H_interpolated')./abs(H_interpolated').^2;

    %% Demodulation
    
    dem_symbol = qamdemod(X_equ,4);
    
    sym_rem = 0;
    
    dem_symbol = [dem_symbol(2:16,1); dem_symbol(18:32,1); dem_symbol(34:48,1); dem_symbol(50:64,1)]; 
    
    ber = 1-sum(dem_symbol(:) == cons_sym_id(:))/length(dem_symbol);
            
            
end

   

    


function [H_interpolated] = interpolate(H,pilot_loc,Nfft,method)
% Input: H = Channel estimate using pilot sequence
% pilot_loc = Location of pilot sequence
% Nfft = FFT size
% method = ’linear’/’spline’
% Output: H_interpolated = interpolated channel
if pilot_loc(1)>1
    slope = (H(2)-H_est(1))/(pilot_loc(2)-pilot_loc(1));
    H = [H(1)-slope*(pilot_loc(1)-1) H]; pilot_loc = [1 pilot_loc];
end
if pilot_loc(end) <Nfft
    slope = (H(end)-H(end-1))/(pilot_loc(end)-pilot_loc(end-1));
    H = [H H(end)+slope*(Nfft-pilot_loc(end))];
    pilot_loc = [pilot_loc Nfft];
end
if lower(method(1))=='l', H_interpolated=interp1(pilot_loc,H,[1:Nfft]);
else H_interpolated = interp1(pilot_loc,H,[1:Nfft],'spline');
end
end