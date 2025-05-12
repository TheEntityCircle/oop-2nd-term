# Это питоновый скрипт, который компилирует файл 03_vector_bad_timing.cpp
# и перенаправляет поток вывода в файл vector_bad_timing.txt.
#
# Потом строит график через matplotlib, сразу рисует на экране и сохраняет
# в файл vector_capacity.png.
#
# Использование.
# vector_bad_timing ожидает на вход два числа:
#      - максимальный размер вектора;
#      - количество повторов (чем больше, тем более гладкий график).
# На 10000 10000 получается прилично.

import pandas as pd 
import matplotlib.pyplot as plt 
import os

os.system('g++ 03_vector_bad_timing.cpp -o ./vector_bad_timing')
os.system("./vector_bad_timing > ./vector_bad_timing.txt")

data = pd.read_csv("vector_bad_timing.txt").to_numpy() 

x = data[:, 0]
y = data[:, 1]
z = data[:, 2]

plt.plot(x, y)
plt.plot(x, z)

plt.savefig('vector_bad_timing.png')
plt.show()
