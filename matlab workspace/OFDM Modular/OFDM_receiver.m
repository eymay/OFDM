
rx_parallel = reshape(rx,80,83);
rx_parallel = rx_parallel(:,10);
for d=1:83; 
%               Receiver
    %% Removing CP and FFT
    
    %     x_p_cpr = ofdm_sig(n_cpe+1:end,:);
    x_p_cpr = rx_parallel(n_cpe+1:end,:);
    
    X_ffted = fft(x_p_cpr);
    
    %% Channel estimation
    pilot_loc = 1:16:60;
    ls_channel = X_ffted(pilot_loc,1)./pilt;
    
    H_interpolated = interpolate(ls_channel',pilot_loc,Nfft,'spline');
    
    X_equ(:,d) = X_ffted.*conj(H_interpolated')./abs(H_interpolated').^2;
% X_equ = X_ffted
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
% method = �linear�/�spline�
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