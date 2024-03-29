# Это питоновый скрипт, который компилирует файл 03_deque_bad_timing.cpp
# и перенаправляет поток вывода в файл deque_bad_timing.txt.
#
# Потом строит график через matplotlib, сразу рисует на экране и сохраняет
# в файл deque_capacity.png.
#
# Использование.
# deque_bad_timing ожидает на вход два числа:
#      - максимальный размер вектора;
#      - количество повторов (чем больше, тем более гладкий график).
# На 10000 10000 получается прилично.

import pandas as pd 
import matplotlib.pyplot as plt 
import os

os.system('g++ 01_string_timings.cpp -o ./string_timing')
os.system("./string_timing > ./string_timing.txt")

data = pd.read_csv("string_timing.txt").to_numpy() 

x = data[:, 0]
y = data[:, 1]
z = data[:, 2]

plt.plot(x, y)
plt.plot(x, z)

plt.savefig('string_timing.png')
plt.show()
