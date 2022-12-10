function [receiveTime,overrunCount] = USRP_OFDM_receiver()

Duration = 10;
        MasterClockRate = 20e6;
        DecimationFactor = 1;
        SamplesPerFrame = 10000;

        SampleRate = MasterClockRate/3;
        FrameDuration = SamplesPerFrame/SampleRate;
        Iterations = Duration/FrameDuration;

        rx = comm.SDRuReceiver('Platform','B200','SerialNum','31FD9D5', ...
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
        
       OFDM_receiver
       
       receiveTime = toc;
       overrunCount = count;
       release(rx);
end

