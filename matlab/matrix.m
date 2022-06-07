
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

% deleting all the element of a row of an  array
%m2(:,2) = []
%m2

% deleting all the element of a column of an  array
m2(2,:) = []
m2


