# Это питоновый скрипт, который компилирует файл 01_vector_internals_capacity.cpp
# и перенаправляет поток вывода в файл vector_capacity.txt.
#
# Потом строит график через matplotlib, сразу рисует на экране и сохраняет
# в файл vector_capacity.png.
#
# Использование.
# vector_capacity ожидает на вход одно число - максимальный размер вектора.

import pandas as pd 
import matplotlib.pyplot as plt 
import os

os.system('g++ 01_vector_internals_capacity.cpp -o ./vector_capacity')
os.system("./vector_capacity | awk -F '[ ,]' '{ print $2 \",\" $5 }' > ./vector_capacity.txt")

data = pd.read_csv("vector_capacity.txt").to_numpy() 

x = data[:, 0]
y = data[:, 1]

plt.plot(x, y)
plt.plot(x, x)

plt.savefig('vector_capacity.png')
plt.show()
