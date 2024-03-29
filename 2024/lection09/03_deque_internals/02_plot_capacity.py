# Это питоновый скрипт, который компилирует файл 01_deque_internals_capacity.cpp
# и перенаправляет поток вывода в файл deque_capacity.txt.
#
# Потом строит график через matplotlib, сразу рисует на экране и сохраняет
# в файл deque_capacity.png.
#
# Использование.
# deque_capacity ожидает на вход одно число - максимальный размер вектора.

import pandas as pd 
import matplotlib.pyplot as plt 
import os

os.system('g++ 01_deque_internals_capacity.cpp -o ./deque_capacity')
os.system("./deque_capacity | awk -F '[ ,]' '{ print $2 \",\" $5 }' > ./deque_capacity.txt")

data = pd.read_csv("deque_capacity.txt").to_numpy() 

x = data[:, 0]
y = data[:, 1]

plt.plot(x, y)
plt.plot(x, x)

plt.savefig('deque_capacity.png')
plt.show()
