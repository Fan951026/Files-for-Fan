function[stogram]=CalHist(inputIm,histrogram)
input = inputIm(:);

if histrogram == 1
B = [];
for i=1:256
    B(i,1) = i;
    B(i,2) = 0;    
end
   for i=1:length(input)
       for j=1:length(B)
           if input(i) == B(j,1)
           B(j,2) = double(B(j,2))+double(1); 
           end
       end
   end
  stogram = B ;
   
elseif histrogram == 2
    B1 = [];
for i=1:256
    B1(i,1) = i;
    B1(i,2) = 0;    
end
    [row,col] = size(inputIm);
   for i=1:length(input)
       for j=1:length(B1)
           % B1(input(i) + 1, 2) = B1(input(i) + 1, 2) + 1;
            if input(i) == B1(j,1)
            B1(j,2) = (double(B1(j,2))+double(1)); 
            end
       end
   end
   B1(:,2) = double(B1(:,2)) / (double(row)*double(col));
   
    stogram = B1;
end



end