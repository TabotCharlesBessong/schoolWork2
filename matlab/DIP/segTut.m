clc
clear all
close all
warning off
x = imread('images/12.jpg'); %3,4,5,6,8,11
figure;
imshow(x);
title('Original Image');

grayImage = rgb2gray(x);

edge_detected_image = imfill(imclose(edge(grayImage,'canny'),strel('disk',3,0)),'holes');
figure;
imshow(edge_detected_image);
title('edge_detected_image');
