a = imread('22.jpg');

subplot(2,2,1)
imshow(a)


newIm = rgb2gray(a);
subplot(2,2,2)
imshow(newIm)

newImm = im2double(a);
subplot(2,2,3)
imshow(newImm)

adj = imadjust(newIm,[0.1,0.8],[0.5,0.8],0.8);
subplot(2,2,4)
imshow(adj)