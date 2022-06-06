
format compact

age = 12

if age >= 5 && age <=19
  disp('You are still in secondary school')
else
  disp('You are in the university')
end

switch age
  case 5
    disp("Go to kindergarten")
  case num2cell(6:13)
    disp("middle school")
  otherwise
    disp("stay at home")
 end
