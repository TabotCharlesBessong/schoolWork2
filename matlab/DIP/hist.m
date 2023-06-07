a = imread('22.jpg');
subplot(3,2,1)
imshow(a)

newIm = rgb2gray(a);
subplot(3,2,3)
imshow(newIm)

subplot(3,2,4)
imhist(newIm);

eqim = histeq(newIm);%Purpose for equalization is to improve the contrast

subplot(3,2,5)
imshow(eqim)

subplot(3,2,6)
imhist(eqim);






