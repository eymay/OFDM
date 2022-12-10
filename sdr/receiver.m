function [receiveTime,overrunCount] = receiver()
        Duration = 10;
        MasterClockRate = 20e6;
        DecimationFactor = 1;
        SamplesPerFrame = 10000;

        SampleRate = MasterClockRate/3;
        FrameDuration = SamplesPerFrame/SampleRate;
        Iterations = Duration/FrameDuration;

        rx = comm.SDRuReceiver('Platform','B200','SerialNum','31FD9C0', ...
                       'MasterClockRate',MasterClockRate, ...
                       'DecimationFactor',DecimationFactor, ...
                       'OutputDataType','double');
        count = 0;
        rx();
        disp('Started Reception...');
        tic
        for i = 1:Iterations
            [data,~,overrun] = rx();
            if overrun
              count = count+1;
            end  
        end     
       %convert the data to row vector for demodulat?on     
       data = reshape(data,1,[]);   
       dem = diff(data);                 
       dem = [0,dem];
       size(dem)
       fc = 100;
       Fs = 1000 ; 
       %dt = 1/Fs;
       t = 0:1:361;
       size(t)
       size(data)
       r_lo = dem.*(cos(2*pi*fc*t));
       [b,a] = butter(10,2*fc/Fs);
       r_flt = filter(b,a,r_lo);
              
       plot(t,r_flt)
       
       receiveTime = toc;
       overrunCount = count;
       release(rx);
end

