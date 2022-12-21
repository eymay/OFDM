function z = THAL_farrow_fractional_interpol(x_s,alpha)

% Istanbul Technical University Wireless Communication Research Laboratory
% İstanbul Teknik Üniversitesi Telsiz Haberleşme Araştırma Laboratuvarı

% This function implements Farrow Fractional Interpolation
% (DOI:10.1109/ISCAS.1988.15483) for error.

% The inputs are as follows:
% alpha : Interpolation factor
% x_s   : Vector to be interpolated

C = [-0.013824  0.003143  0.055298 -0.012573;...
    0.054062 -0.019287 -0.216248  0.077148;...
    -0.157959  0.100800  0.631836 -0.403198;...
    0.616394 -1.226364 -0.465576  0.905457;...
    0.616394  1.226364 -0.465576 -0.905457;...
    -0.157959 -0.100800  0.631836  0.403198;...
    0.054062  0.019287 -0.216248 -0.077148;...
    -0.013824 -0.003143  0.055298  0.012573];

m = 0:3;
y_m = x_s*C;
z = sum(alpha.^m.*y_m,2);

end