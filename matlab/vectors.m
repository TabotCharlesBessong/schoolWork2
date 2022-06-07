
format compact

vt1 = [5 3 2 1]
vL = length(vt1)
vt1S = sort(vt1)
vt1S1 = sort(vt1,'descend')
vt2 = 5:10
vt3 = 2:3:20
vt4 = [vt1 vt2]
vt4(1)
vtEnd = vt4(end)
vt4(1) = 0
vt3(11) = 33
vt4(1:3)
vt4([2 4 6])

vc1 = [2;3;4;5]
vt5 = [1 2 3 4 ]

v1 = vc1 * vt5

% Dot product
%vtDot = vt1 * vt5'
vtDot2 = dot(vt1,vt5)
%vtCross = cross(vc1, vt5)

vt8 = linspace(1,20,4)
vt9 = logspace(1,3,3)

