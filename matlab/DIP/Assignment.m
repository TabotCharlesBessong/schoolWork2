d= imread('22.tif');

x= 3000
y= 2000
r= 2


[xgrid, ygrid] = meshgrid(1:size(d,2), 1:size(d,1));

mask = ((xgrid-x).^2 + (ygrid-y).^2) <= r.^2;

values = d(mask);

d(2:2000,:)=1;


image(d)