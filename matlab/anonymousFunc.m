
format compact

cubeVol = @ (l,w,h) l * w * h
cV = cubeVol(4,4,4)

function sol = doMath(func,num)
  sol = func(num)

end

mul3 = @ (x) x * 3
sol = doMath(mul3,4)
