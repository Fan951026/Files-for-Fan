function[maxValue,minValue,meanValue,mediaValue]=FindInfo(oriIm)
oriIm=oriIm(:);
maxValue=oriIm(1);
minValue=oriIm(1);

count = mod(length(oriIm),2);
sorted = sort(oriIm);
temp=oriIm(1);

for i=2:length(oriIm)
    if oriIm(i) > maxValue
        maxValue = oriIm(i);
    end
end
for i=2:length(oriIm)
    if oriIm(i)<minValue
        minValue = oriIm(i);
    end
end

for i=2:length(oriIm)
  temp = oriIm(i) + temp;    
end
meanValue = temp/length(oriIm);


if count == 0
    num1 = sorted(round(length(sorted)/2+0.5));
    num2 = sorted(round(length(sorted)/2-0.5));
    mediaValue = (num1+num2)/2;
elseif count == 1
    mediaValue = sorted(round(length(oriIm)/2));
end 


end