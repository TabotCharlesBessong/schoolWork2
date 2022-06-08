
format compact




function vol = cylinderVlo(rad,hei)
  vol = pi *  rad^2 * hei
end

cylinderVlo(20,30)

function chnageName()
  changeMe = 10
  class(changeMe)
end

chnageMe = 6
chnageName()
disp(chnageMe)

function ran =  getRandomNumber()
  ran = randi([1,100])
end

getRandomNumber()

% a function that can return more than 1 value
function [conVol , cynlinderVol] = getVols(rad , hei)
  cynlinderVol = pi * rad^2 * hei
  conVol = 0.33 * cynlinderVol
end

[con , cy] = getVols(10,20)

function sum = getSum(varargin)
  sum = 0
  for k = 1:length(varargin)
    sum = sum + varargin{k}(1)
  end
end

sum = getSum(1,2,3,4,5,6,7,8,9,10,11)


