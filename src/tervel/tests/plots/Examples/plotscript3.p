reset
set autoscale fix
set palette defined (0 'white', 1 'green')
set tics scale 0
unset cbtics
set cblabel 'Score'
unset key

set term wxt size 1200,720

xnumtics = 4
set for [i=0:(xnumtics-1)] xtics add (sprintf("m%d", i) i)
set xtics add (sprintf("sum") xnumtics)

#set xtics ("A" 0, "B" 1, "C" 2, "D" 3, "E" 4)

plot 'data.txt' matrix with image,\
     '' matrix using 1:2:(sprintf('%.2f', $3)) with labels font ',16'
