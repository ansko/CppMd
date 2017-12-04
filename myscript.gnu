#!/usr/bin/env gnuplot

set terminal png size 1024, 768
set output 'MechModels.png'
#set xtics 0.25 nomirror
set xtics nomirror
#set yrange [0 to 1000000]
#set xrange [0 to 0.1]
set ytics nomirror
set pointsize 3




plot 'log' u 1 w l lc rgb "red" title "ALL",\
 'log' u 2 w l lc rgb "green" title "POT/2",\
 'log' u 3 w l lc rgb "blue" title "KIN"
