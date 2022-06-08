
format compact

function val = facto(num)
  if num == 1 || num == 0
    val = 1
  else
    val = num * facto(num - 1)
  end
end

facto(4)

% inbuilt factorial functio
fact = factorial(6)
