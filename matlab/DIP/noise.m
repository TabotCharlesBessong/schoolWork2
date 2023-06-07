clc
clear all
close all
warning off

a = imread('images/30.jpg');
subplot(3,3,1)
imshow(a)
title('Original Image');

b= rgb2gray(a);
subplot(3,3,2)
imshow(b)
title('Gray Image');

c=imnoise(b,'salt & pepper', 0.2);
subplot(3,3,3)
imshow(c)
title('Noise Image');

d=imfilter(c,fspecial('gaussian',[8,8],7)); %average, laplacian, prewitt, sobel,
subplot(3,3,4)
imshow(d)
title('Gaussian Filtered Image');

d=imfilter(c,fspecial('average')); %average, laplacian, prewitt, sobel,
subplot(3,3,5)
imshow(d)
title('Average Filtered Image');

g=imbinarize(d, 0.5); %im2bw
subplot(3,3,6)
imshow(d)
title('Binarized Filtered Image');



d=imfilter(c,fspecial('laplacian')); %average, laplacian, prewitt, sobel,
subplot(3,3,7)
imshow(d)
title('Laplacian Filtered Image');

d=edge(b,'sobel'); %average, laplacian, prewitt, sobel,
subplot(3,3,8)
imshow(d)
title('Sobel Edged Image');

d=edge(b,'prewitt'); %average, laplacian, prewitt, sobel,
subplot(3,3,9)
imshow(d)
title('prewitt Edged Image');


h=[-1 -1 -1
    2 2 2
    -1 -1 -1]

v=[-1 2 -1
    -1 2 -1
    -1 2 -1]
r= [2 -1 -1
    -1 2 -1
    -1 -1 2]
s=[-1 -1 2
    -1 2 -1
    2 -1 -1]

