reset
set autoscale fix
set palette defined (0 'white', 1 'green')
set tics scale 0
unset cbtics
set cblabel 'Score'
unset key

set term wxt size 1200,720
set origin 0,0

set multiplot layout 1,2
set size 0.7,1
xnumtics = 5
set for [i=0:xnumtics] xtics add (sprintf("m%d", i) i)

#set xtics ("A" 0, "B" 1, "C" 2, "D" 3, "E" 4)

plot 'data.txt' matrix with image,\
     '' matrix using 2:1:(sprintf('%.2f', $3)) with labels font ',16'

set size 0.3,1
set origin 0.7,0

set xtics ("SUM" 0)
set xrange [-0.5:0.5]

set palette defined (-1 'red', 0 'white', 1 'green')

plot 'test.dat' matrix using 1:2:3 with image,\
     '' matrix using 1:2:($3 == 2 ? "" : sprintf('%.2f', $3)) with labels font ',16'

unset multiplot
