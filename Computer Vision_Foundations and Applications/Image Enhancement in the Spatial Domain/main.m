 food=imread('Food.jpg');
newmin = 0;
newmax = 255;
[scaledFood,transFunc] = Scaling(food,[newmin newmax]);

x = unique(food);
y = transFunc;
figure;
plot(x,y);
title('Transformation Function graph');
xlabel('Old number');
ylabel('new number');
pause;

%--------finished problem 1;
matScaledFood = imadjust(food,[double(min(food(:)))/255,double(max(food(:)))/255],...
    [newmin/255, newmax/255]);
figure;
subplot(1,2,1);
imshow(scaledFood);
title('my Scaled');
subplot(1,2,2);
imshow(matScaledFood);
title('MatLab Scale');
pause;
%--------finished problem2;
SF_h = CalHist(scaledFood,1);
SF_n = CalHist(scaledFood,2);
MSF_h = CalHist(matScaledFood,1);
MSF_n = CalHist(matScaledFood,2);

figure;
subplot(2,2,1)
y1 = SF_n(:,2);
bar(0:double(1/255):1,y1);
title('normalized for scaledFood');
xlabel('X');
ylabel('Y');
subplot(2,2,2);
y2 = MSF_n(:,2);
bar(0:double(1/255):1,y2);
title('normalized for matscaledFood');
xlabel('X');
ylabel('Y');
subplot(2,2,3);
y3 = SF_h(:,2);
bar(0:1:255,y3);
title('histogram for scaledFood');
xlabel('X');
ylabel('Y');
subplot(2,2,4);
y4 = MSF_h(:,2);
bar(0:1:255,y4);
title('histogram for matscaledFood');
xlabel('X');
ylabel('Y');
pause;
%------finished problem 3----
tic
[HistEqualiza,transF,check] = HistEqualization(food);
%figure;
%imshow(HistEqualiza);
timeElapsed = toc;
D1 = ['In problem 4, my histEqualization took ',num2str(timeElapsed),' second to run.'];
disp(D1);
pause;
%------finished problem 4----

tic
[matHisteq,tranM] = histeq(food);
timeElapsed2 = toc;
D2 = ['In problem 5, MatLab histEqualization took ',num2str(timeElapsed2),' second to run.'];
disp(D2);


figure;
subplot(1,2,1);
imshow(HistEqualiza);
title('HistEqualiza');
subplot(1,2,2);
imshow(matHisteq);
title('MatLab HistEqualiza');




figure;
x_1 = 1:256;
y_1 = transF;
subplot(1,2,1);
plot(x_1,y_1);
title('Transformation Function graph');
xlabel('X');
ylabel('New number');

x_2 = 1:256;
y_2 = tranM;
subplot(1,2,2);
plot(x_2,y_2);
title('Transformation matlab graph');
xlabel('X');
ylabel('New number');
Compare(timeElapsed,timeElapsed2);

CompareF(transF,tranM);

fprintf('After I read the implementation detail of the chose function for problem 5. I find out that my code was not good enough, their code can handle more things.')



function Compare(first,second)
if first > second
    disp('Matlab is more faster than my!');
else
   disp('my is more faster than Matlab!');
end
end
function CompareF(my,mat)
count = 0;
for i=1:length(my)
    if my(i)~=mat(i)
        count = count + 1; 
    end
end
D0 = ['The different between my and matlab histogram equalization transfom function is ',num2str(count), ' pixel'];
disp(D0);


end




