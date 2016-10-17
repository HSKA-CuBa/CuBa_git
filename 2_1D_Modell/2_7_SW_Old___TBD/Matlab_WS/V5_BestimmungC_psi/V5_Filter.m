mean4  = zeros(size(psi__d));
mean8  = zeros(size(psi__d));
mean16 = zeros(size(psi__d));

for k = 1:length(mean4)
    if(k < 4)
        mean4(k) = sum(psi__d(1:k))/k;
    else
        mean4(k) = sum(psi__d(k-3:k))/4;
    end
end
for k = 1:length(mean8)
    if(k < 8)
        mean8(k) = sum(psi__d(1:k))/k;
    else 
        mean8(k) = sum(psi__d(k-7:k))/8;
    end
end
for k = 1:length(mean16)
    if(k < 16)
        mean16(k) = sum(psi__d(1:k)) / k;
    else
        mean16(k) = sum(psi__d(k-15:k))/16;
    end
end

plot(time, psi__d, time, mean4, time, mean8, time, mean16); grid
