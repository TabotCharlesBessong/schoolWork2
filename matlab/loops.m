
format compact

% printing from 1 to 10
%for i = 1:10
%  disp(i)
%end

% printing the decrement from 1 to 10

for i = 10:-1:0
  disp(i)
end

% printing the increment from 1 to 10

fprintf("\n")
for i = 1:+1:20
  disp(i)
end

% printing with specific values

for i = [2 3 4]
  disp(i)
end

%printing values of array

m4 = [1 2 3; 4 5 6]

for i = 1:2
  for j = 1:3
    disp(m4(i,j))
  end
end

%printing values from a vector

vt1 = [6 7 8 ]
for i = 1:length(vt1)
  disp(vt1(i))
end




