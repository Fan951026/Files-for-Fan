function [blurredIm] = BlurImage(oriIm)


if size(oriIm,3) == 1
    array1 = oriIm(1:length(oriIm),1:length(oriIm),1:1);
for i=1:length(array1)/2
    x=i*2-1;
    for j=1:length(array1)/2
        y=j*2-1;
        temp = (array1(x,y)+ array1(x,y+1) + array1(x+1,y)+ array1(x+1,y+1))/4;
        array1(x:x+1,y:y+1) = temp;
    end
end
    blurredIm = array1;
    
elseif size(oriIm,3) == 3
    
   array2 = oriIm(1:length(oriIm),1:length(oriIm),1:1);

for i=1:length(array2)/2
    x=i*2-1;
    for j=1:length(array2)/2
        y=j*2-1;
        temp = (array2(x,y)+ array2(x,y+1) + array2(x+1,y)+ array2(x+1,y+1))/4;
        array2(x:x+1,y:y+1) = temp;
    end
    
end


   array3 = oriIm(1:length(oriIm),1:length(oriIm),2:2);

for i=1:length(array3)/2
    x=i*2-1;
    for j=1:length(array3)/2
        y=j*2-1;
        temp = (array3(x,y)+ array3(x,y+1) + array3(x+1,y)+ array3(x+1,y+1))/4;
        array3(x:x+1,y:y+1) = temp;
    end
    
end


   array4 = oriIm(1:length(oriIm),1:length(oriIm),3:3);

for i=1:length(array4)/2
    x=i*2-1;
    for j=1:length(array4)/2
        y=j*2-1;
        temp = (array4(x,y)+ array4(x,y+1) + array4(x+1,y)+ array4(x+1,y+1))/4;
        array4(x:x+1,y:y+1) = temp;
    end
    
end



blurredIm = array2;
blurredIm(:,:,2) = array3;

blurredIm(:,:,3) = array4;

end


end