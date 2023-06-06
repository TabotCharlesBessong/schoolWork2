d = imread('22.jpg');

red =d(:,:,1);
green = d(:,:,2);
blue = d(:,:,3);

subplot(2,2,1);
imshow(d);

subplot(2,2,2);
imshow(red)

subplot(2,2,3);
imshow(green)

subplot(2,2,4);
imshow(blue)

whos
