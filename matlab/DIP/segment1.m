clc
clear all
close all
warning off
x = imread('images/3.jpg'); %3,4,5,6,8,11
figure;
imshow(x);
title('Original Image');

grayImage = rgb2gray(x);

figure;
imshow(grayImage);
title('Gray Image');

% Apply Gaussian Blur
blurredImage = imgaussfilt(grayImage, 3); % Adjust the standard deviation (sigma) as needed

figure;
imshow(blurredImage);
title('Blurred Image');

% Apply Median Filtering
filteredImage = medfilt2(blurredImage, [3, 3]); % Adjust the window size as needed
figure;
imshow(filteredImage);
title('Filtered Image');


% Image Enhancement
enhancedImage = histeq(filteredImage); % Perform histogram equalization1
figure;
imshow(enhancedImage);
title('Enhanced Image');

edge_detected_image = bwareaopen(imopen(imfill(imclose(edge(grayImage,'canny'),strel('disk',3)),'holes'),strel(ones(3))),10);
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