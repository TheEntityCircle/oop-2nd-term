# Это баш скрипт, который компилирует файл 01_deque_internals_capacity.cpp
# и перенаправляет поток вывода в файл deque_capacity.txt.
# 
# Потом строит график через gnuplot, сразу рисует на экране и сохраняет 
# в файл deque_capacity.png.
# Это пакет, его можно поставить из стандартного репозитория.
# Для Ubuntu:
# sudo apt install gnuplot
#
# Использование. 
# deque_capacity ожидает на вход одно число - максимальный размер вектора.

#!/bin/sh
g++ 01_deque_internals_capacity.cpp -o ./deque_capacity
set -e

./deque_capacity | awk -F '[ ,]' '{ print $2 " " $5 }' > deque_capacity.txt
gnuplot -p -e "\
    set grid; \
    y(x) = x; \
    set style line 1 lt 1 lc rgb 'red' lw 2; \
    set style line 2 lt 2 lc rgb 'blue' lw 2 dashtype 3; \
    set ylabel 'capacity'; \
    set xlabel 'size'; \
    plot y(x) ls 2, 'deque_capacity.txt' ls 1 with l; \
    set terminal png font arial 14 size 800,600 ; \
    set output 'deque_capacity.png' ; \
    plot y(x) ls 2, 'deque_capacity.txt' ls 1 with l; \
"
