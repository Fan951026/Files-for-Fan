function[scaledIm,transFunc]=Scaling(inputIm,range)
input = inputIm(:);
A1 = [];
A = unique(input);
r1 = double(range(2)) - double(range(1));
a1 = double(A(length(A)))-double(A(1));
f1 = r1/a1;


A1 = double(inputIm)*double(f1);  
A1 = double(A1) + (double(range(1)) - double(A(1))*double(f1));

scaledIm = uint8(A1);

transFunc = unique(scaledIm);


end