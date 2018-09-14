function[enhancedIm, transFunc, check]= HistEqualization(inputIm)
input = inputIm(:);
output = inputIm;
    B1 = [];
for i=1:256
    B1(i,1) = i;
    B1(i,2) = 0;  
    B1(i,3) = 0;
    B1(i,4) = 0;
    B1(i,5) = 0;
end
temp = CalHist(inputIm, 2);
B1(:,2) = temp(:,2);
[row,col] = size(inputIm);
%    for i=1:length(input)
%        for j=1:length(B1)
%            if input(i) == B1(j,1)
%            B1(j,5) = (double(B1(j,2))+double(1)); 
%            
%            B1(j,2) = (double(B1(j,2))+double(1)); 
%            end
%        end
%    end
%    B1(:,2) = double(B1(:,2))/(double(row)*double(col));
   
   B1(1,3) = B1(1,2);
   for i=2:length(B1)
            
           B1(i,3) = B1(i-1,3)+ B1(i,2);
               
   end 
  % test = zeros(row, col);
   B1(:,4) = round(B1(:,3)*255.0);
%    for i = 1:row
%        for j = 1:col
%           output(i, j) = B1(inputIm(i, j) + 1, 4);
%        end
%    end
    for i=1:row
        for j=1:col
           for z=1:length(B1)
              if inputIm(i,j) + 1 == B1(z,1)
                output(i,j) = B1(z,4);
              end
           end
       end
    end
   enhancedIm = output ;% B1 is the data sheet
   transFunc = B1(:,4) ./ 255;
   check= B1;



end







