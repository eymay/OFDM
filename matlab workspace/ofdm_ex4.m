clear
% BER performance of OFDM in frequency-selective and AWGN channel
SNR=[0 2 4 6 8 10 15 20 30];% dB
N=256; % FFT size
CP_size=1/4; % CP length as a ratio of the OFDM symbol duration
G=N*CP_size;

for num=1:1000
    symbols=2*(randn(1,N)>0)-1; % Random BPSK symbols in each carrier
    time=ifft(symbols)*sqrt(N); % IFFT (using all the subcarriers)
    time_cp=[time(end-N*CP_size+1:end) time];
    L=7;% Number of channel taps
    cir=(randn(1,L)+1i*randn(1,L))/sqrt(2)/sqrt(L);
%     figure
%     stem(cir)
    cfr=fft(cir,N);
%     figure
%     stem(cfr)
    noise = 1/sqrt(2)*(randn(1,N+G) + 1i*randn(1,N+G));
    rec_fading=filter(cir,1,time_cp);
    rec_awgn=time_cp;
    
    for kk=1:length(SNR)
        rec_fading_noisy = rec_fading + noise*10^(-SNR(kk)/20);
        rec_awgn_noisy = rec_awgn + noise*10^(-SNR(kk)/20);
        rec_fading_freq= fft(rec_fading_noisy(G+1:end))/sqrt(N);
        rec_fading_eqz=sign(real(rec_fading_freq.* conj(cfr)./(abs(cfr).^2)));
        rec_awgn_bits= sign(real(fft(rec_awgn_noisy(G+1:end))/sqrt(N)));
        BER_fading(num,kk)=length(find(rec_fading_eqz~=symbols))/N;
        BER_awgn(num,kk)= length(find(rec_awgn_bits~=symbols))/ N;
    end
end

figure(1);clf
semilogy(SNR,mean(BER_fading),'r-*','LineWidth',2)
hold
semilogy(SNR,mean(BER_awgn),'k-o','LineWidth',2)
xlabel('SNR (dB)'); ylabel('BER'); grid;
legend('Multipath dispersive channel','AWGN channel')