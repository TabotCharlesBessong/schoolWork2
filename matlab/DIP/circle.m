close all;
clear all;
clc;


x_center = 2;
y_center = 2;

radius = 1;

t=0:pi/50:2*pi;

x=radius*cos(t) + x_center;
y=radius*sin(t) + y_center;

patch(x,y,'red');
axis equal