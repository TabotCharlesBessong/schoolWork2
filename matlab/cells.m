
format compact

% cells can take multiple datatypes values and you can as well assign them a fixed size shape which will change as you add more element

c1 = {'Hello', 21, 2.4 , [24 1 32 5]}
c2 =  cell(5)
c1{1}
%c1{3}(2)
length(c1)
c1{5} = 'Messi GOAT'
length(c1)

for i = 1:length(c1)
  disp(c1{i})
end
