function ran_data = zipfian(N, theta)
alpha = 1 / (1 -theta);
zetan = sum([1:N].^(-theta));
eta = (1-(2.0/N)^(1-theta))/(1-sum([1,2].^(-theta))/zetan);

ran_data = rand(1,N);
for i = 1:N
    u = ran_data(i);
    uz = u * zetan;
    if(uz < 1) 
        ran_data(i) = 1;
    elseif(uz < 1 + 0.5^theta)
        ran_data(i) = 2;
    else
        ran_data(i) = floor(N * (eta*u -eta + 1)^alpha);
    end
end