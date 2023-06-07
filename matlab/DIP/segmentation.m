
clc
clear all
close all
warning off
x = imread('images/12.jpg');
figure;
imshow(x);
title('Original Image');

edge_detected_image = bwareaopen(imopen(imfill(imclose(edge(rgb2gray(x),'canny'),strel('disk',3,0)),'holes'),strel(ones(3,3))),1500);

figure;
imshow(edge_detected_image);
title('Edge Detected Image');

red_processed = x(:,:,1).*uint8(edge_detected_image);
green_processed = x(:,:,2).*uint8(edge_detected_image);
blue_processed = x(:,:,3).*uint8(edge_detected_image);
op = cat(3,red_processed,green_processed,blue_processed);
figure;
imshow(op);
title('Output Image');