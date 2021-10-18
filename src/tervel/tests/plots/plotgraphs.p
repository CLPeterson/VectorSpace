reset
set autoscale fix
set palette defined (-1 'blue', 0 'white', 1 'green')
set tics scale 0
unset cbtics
set cblabel 'Score'
unset key
set cbrange [-1:1]

# set term wxt size 2000,1000

set terminal png size 2000,1100

set output outputname

set origin 0,0

set multiplot layout 1,2
set size 0.6,0.9
xnumtics = 32
set for [i=0:xnumtics] xtics add (sprintf("m%d", i) i)
set for [i=0:xnumtics] ytics add (sprintf("%d", i) i)

plot 'method.txt' matrix using 2:1:3 with image,\
     '' matrix using 2:1:(sprintf('%d', $3)) with labels font ',16'


set size 0.2,0.9
set origin 0.6,0
set xtics ("PROMOTE/DEMOTE" 0)
set xrange [-0.5:0.5]

plot 'promote.txt' matrix using 1:2:3 with image,\
     '' matrix using 1:2:(sprintf('%.5f', $3)) with labels font ',16'

set size 0.2,0.9
set origin 0.8,0
set xtics ("SUM" 0)

unset colorbox
#set colorbox
set palette defined (-1 'red', 0 'white', 1 'green')
set tics scale 0
unset cbtics
set cblabel 'Score'
unset key
set cbrange [-1:1]


plot 'sum.txt' matrix using 1:2:3 with image,\
     '' matrix using 1:2:(sprintf('%.5f', $3)) with labels font ',16'

set size 1,0.1
set origin 0,0.9
unset xtics
set ytics ("STATE" 0)
set xrange [-0.5:24]
set yrange [-0.5:0.5]

plot 'state.txt' matrix using 1:2:($3 == -999 ? "   EMPTY" :sprintf('%d', $3)) with labels font ',20'

unset multiplot
