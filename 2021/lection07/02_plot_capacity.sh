#!/bin/sh

set -e

./vector_capacity | awk -F '[ ,]' '{ print $2 " " $5 }' > capacity.txt
gnuplot -p -e "\
    set grid; \
    y(x) = x; \
    set style line 1 lt 1 lc rgb 'red' lw 2; \
    set style line 2 lt 2 lc rgb 'blue' lw 2 dashtype 3; \
    set ylabel 'capacity'; \
    set xlabel 'size'; \
    plot y(x) ls 2, 'capacity.txt' ls 1 with l; \
"
