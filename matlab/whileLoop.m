
format compact

i = 1
while i < 20
  if(mod(i,2)) == 0
    disp(i)
    i = i + 1
    continue
  end
  i = i + 1

  if i >= 20
    break
  end
end

