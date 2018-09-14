%---Xuecong Fan---
%---Assignment 1----
%---push any key for continue---


A=imread('peppers.bmp');
figure('Name','RGB Original Image');
imshow(A);
title('RGB Original Image');
pause
%-----Finish Solving Problem 1-----
f2 = figure;
B = rgb2gray(A);
TB= transpose(B);
temp_HB1=B(1:512/2,1:512);
temp_HB2=B(512/2:512,1:512);
HB = [temp_HB2;temp_HB1];
FB = fliplr(B);
subplot(2,2,1);
imshow(B);
title('B');
subplot(2,2,2);
imshow(TB);
title('TB');
subplot(2,2,3);
imshow(HB);
title('HB');
subplot(2,2,4);
imshow(FB);
title('FB');
pause
%----Finish Solving Problem 2----

B1 = double(B);
real_Median = median(B(:));
real_Max = max(B(:));
real_Min = min(B(:));
real_Mean = mean(B(:));
[maxValue,minValue,meanValue,mediaValue]=FindInfo(B1);


pause
%----Finish Solving Problem 3 -----

C = double(B);
C = C./max(max(C));
figure('Name','Normalized Grayscale Image');
imshow(C);
title('Normalized Grayscale Image');

D = C;
D(1:length(D)/2,1:length(D)/2) = C(1:length(C)/2,1:length(C)/2).^1.25;
D(length(D)/2:length(D),length(D)/2:length(D))=C(length(C)/2:length(C),length(C)/2:length(C)).^0.75 ;
D(1:length(D)/2,length(D)/2:length(D)) = C(1:length(C)/2,length(C)/2:length(C));
D(length(D)/2:length(D),1:length(D)/2) = C(length(C)/2:length(C),1:length(D)/2);
figure('Name','Processed Grayscale Image');
imshow(D);
title('Processed Grayscale Image');
imwrite(D,'X_D.jpg');

pause
%----Finish Solving Problem 4-----


sed1 = C >= 0.3;
sed1 = double(sed1);
bw1 = sed1;
%--first method--

sed=C;
t = find(sed >= 0.3);
sed(t) = 1;
t1 = find(sed<0.3);
sed(t1) = 0;
bw2 = sed;
%--second method--

bw3 = im2bw(C,0.3);


if isequal(bw1,bw2)&& isequal(bw1,bw3)
   disp('Both of my methodsworked');
end
    
    
    
    
    
%--matlab method--
figure('Name','Both of my methods worked'); 
subplot(1,3,1);
imshow(bw1);
title('my first method');
subplot(1,3,2);
imshow(bw2);
title('my second method');
subplot(1,3,3);
imshow(bw3);
title('Matlab method');







pause
%----Finish Solving Problem 5----

A1 = im2double(A);
Blue = BlurImage(A1);


f4 = figure;
B_1 = im2double(B);
Blue2 = BlurImage(B_1);


subplot(2,2,1);
imshow(A);
title('A');
subplot(2,2,2);
imshow(B);
title('B');
subplot(2,2,3);
imshow(Blue);
title('BA');
subplot(2,2,4);
imshow(Blue2);
title('BB');
pause
%----Finish Solving Problem 6----

 clear
 close all


%----Finish Solving Problem 7----
