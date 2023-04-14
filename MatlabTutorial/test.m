 img = imread('you1.jpg');
 
 subplot(2,3,1);
 a = imadd(img,100);
 imshow(a); 
 
 subplot(2,3,3);
 b = imadd(img,50);
 imshow(b);
 
 subplot(2,3,2);
 c = imadd(img,200);
 imshow(c);
 
 subplot(2,3,4);
 d = im2bw(img,0.49);
 imshow(d);
 
 subplot(2,3,5);
 e = im2bw(img,0.29);
 imshow(e);
 
 subplot(2,3,6);
 f = im2bw(img,0.83);
 imshow(f);
 
 %subplot(m,n,position)
 % 2 by 3 at the 4th position