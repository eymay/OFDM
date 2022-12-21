
[interpolated_signal, eps_plt] = THAL_meyr_oeder_symbol_sync(1,64,y);


for d=1:80; 
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