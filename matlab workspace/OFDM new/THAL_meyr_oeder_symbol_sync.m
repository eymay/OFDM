function [interpolated_signal, eps_plt] = THAL_meyr_oeder_symbol_sync(os,L,received_signal)

% Istanbul Technical University Wireless Communication Research Laboratory
% İstanbul Teknik Üniversitesi Telsiz Haberleşme Araştırma Laboratuvarı

% This function implements a blind symbol synchronisation algorithm which
% uses Meyr-Oeder Timing Error Estimation Method (DOI:10.1109/26.1476) and
% Farrow Fractional Interpolation (DOI:10.1109/ISCAS.1988.15483) for error
% correction.

% The inputs are as follows:
% os              : Oversampling factor
% L               : Frame length for Meyr-Oeder Timing Error Estimation
% received_signal : The received signal after downconversion and filtering

% The outputs are as follows:
% interpolated_signal : Corrected signal
% eps_plt             : Variation of the timing error

k     = length(received_signal)/os;    % # of symbols

eps_p = 0;
sfob  = 0;                             % Step forward or backward according to the variation of timing error  

for ii = 1:(k/L-1)-1
    
    frame_ind = ((1+ii*os*L):((ii+1)*os*L))+sfob;
    r_k = received_signal(frame_ind);
    x_k = abs(r_k).^2;
    x_m = sum(x_k.*exp(-1i*2*pi*(0:(L*os-1))/os));
    eps = (-0.5/pi*angle(x_m));        % Timing error for the frame ii
    eps_plt(ii) = eps;                 % Variation of timing error
    
    step = round(eps*os);
    frac = eps*os-step;
    
    
    if frac<0      % 4 backward 3 forward samples
        for jj = 0:(L-1)
            interpolated_signal(1+(ii-1)*L+jj) = THAL_farrow_fractional_interpol(received_signal(((1+ii*os*L+jj*os):(ii*os*L+(jj+1)*os))+step-4+sfob),0.5+frac);
        end
    else           % 3 backward 4 forward samples 
        for jj = 0:(L-1)
            interpolated_signal(1+(ii-1)*L+jj) = THAL_farrow_fractional_interpol(received_signal(((1+ii*os*L+jj*os):(ii*os*L+(jj+1)*os))+step-3+sfob),frac-0.5);
        end
    end
    
    sfob = (-((eps-eps_p)>0.50)+((eps-eps_p)<-0.50))*os;
    eps_p = eps;
    
end
end

