

img1 = imread('you2.jpg');
subplot(3,3,1);
imhist(img1);

img2 = imread('house1.jpg');
subplot(3,3,2);
imhist(img2);

eqImg = histeq(rgb2gray(img2));
subplot(3,3,5);
imhist(eqImg);

bw = im2double(img2);
subplot(3,3,4);
imshow(bw);

imtool(bw);
subplot(3,3,3);
imshow(bw);

adj = imadjust(bw,[0.33,0.71],[],7);
subplot(3,3,6);
imtool(adj);