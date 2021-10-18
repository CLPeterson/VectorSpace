reset
set autoscale fix
set palette defined (-1 'red', 0 'white', 1 'green')
set tics scale 0
unset cbtics
set cblabel 'Score'
unset key

set xrange [-0.5:0.5]

plot 'test.dat' matrix using 1:2:3 with image,\
     '' matrix using 1:2:($3 == 2 ? "" : sprintf('%.2f', $3)) with labels font ',16'
