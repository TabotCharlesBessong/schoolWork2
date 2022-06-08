
format compact

m1 = [2 3 4; 4 6 8]
mRN = length(m1)
mL = numel(m1)
mS = size(m1)
[nRows,nCols] = size(m1)

m2 = randi([10,20],2)
m2(1,2) = 24
m2
%change all row values
m2(1,:) = 17
%chnaging all column values
m2(:,1) = 32
% equl , find(matrix,paramter) isequal
mg = m2 > 15
%sum(mg,'all')

% deleting all the element of a row of an  array
%m2(:,2) = []
%m2

% deleting all the element of a column of an  array
%m2(2,:) = []
%m2

m4 = [1:3;4:6]
m5 = [2:4;5:7]
m4 + m5
m4 .* m5
m5 - m4

m7 = [1 1 1 1;
      2 2 2 2;
      3 3 3 3]

prod(m7)
cumsum(m7)
cumsum(m2)
cumprod(m5)
rot90(m7)

% reshape reshapes the matrix
reshape(m7,2,6)
% repeat the element in the matrix
repmat(m7,2,1)
% replicate element in the matrix
repelem(m7,2,1)

