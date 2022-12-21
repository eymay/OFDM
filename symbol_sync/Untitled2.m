k = 5; %no of bad states
l = 5; %no of good states
N = 50; %error length
state_vector = linspace(0,k+l,k+l); %good = 1 to 5, bad = 6 to 10
init_state = 1; %inital state
state = init_state;

p = [linspace(0.5, 0.1, k-1) 0]; %pk = 0 
alpha = [linspace(0.5, 0.1, l-1) 0]; %alphal = 0

for i = 1:50
    if state > 5 %bad state case
        to_bad = binornd(1, p(state - 5));
        if to_bad == 1
            state = state + 1 %transitions to next bad state
            error(i) = 1;
        else
            state = 1 %transitions to G1 state
            error(i) = 0;
        end
    end
            
     if state < 5 %good state case
        to_good = binornd(1, alpha(state));
        if to_good == 1
            state = state + 1 %transitions to next good state
            error(i) = 0;
        else
            state = 6 %transitions to B1 state
            error(i) = 1;
        end
     end
end
    
    