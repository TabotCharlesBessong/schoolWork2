clc
clear all
close all
warning off
x = imread('images/12.jpg'); %3,4,5,6,8,11
figure;
imtool(x);
title('Original Image');

grayImage = rgb2gray(x);

% Define the region of interest for seed point selection
roi = [1800, 1000, 1650, 2000]; % [x, y, width, height] of the ROI

% Extract the region of interest
roiImage = grayImage(roi(2):roi(2)+roi(4)-1, roi(1):roi(1)+roi(3)-1);

edge_detected_image = bwareaopen(imopen(imfill(imclose(edge(roiImage,'canny'),strel('disk',3,0)),'holes'),strel(ones(3,4))),1500);

% Create the segmentation mask for the full image based on the edge detection result
segmentationMask = false(size(grayImage));
segmentationMask(roi(2):roi(2)+roi(4)-1, roi(1):roi(1)+roi(3)-1) = edge_detected_image;

figure;
imtool(edge(roiImage,'canny'));
title('edges');

figure;
imtool(segmentationMask);
title('Segmentation Mask');

red_processed = x(:,:,1).*uint8(segmentationMask);
green_processed = x(:,:,2).*uint8(segmentationMask);
blue_processed = x(:,:,3).*uint8(segmentationMask);
op = cat(3,red_processed,green_processed,blue_processed);
figure;
imtool(op);
title('Output Image');