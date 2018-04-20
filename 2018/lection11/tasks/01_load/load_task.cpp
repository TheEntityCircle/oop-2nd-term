#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Класс, представляющий собой некую расчётную задачу
class Task
{
protected:
    int cpuNum;
    int size;

public:
    Task(int cpuNum, int size) {
        this->cpuNum = cpuNum;
        this->size = size;
    }

    // На каком ядре процессора выполняется задача
    int getCPU() const {
        return cpuNum;
    }

    // Оценка сложности задачи (в попугаях)
    int getSize() const {
        return size;
    }
};

// Класс балансировщика, который нужно реализовать
class Balancer
{
public:
    Balancer();

    // Проанализировать текущие задачи
    void analyze(const vector<Task>& tasks);

    // Сообщить общую нагрузку на заданное ядро
    int getLoadForCPU(int cpuNum);
};

int main()
{
    vector<Task> data = { {0, 1}, {1, 10}, {0, 6}, {2, 12}, {3, 5} };
    Balancer b;
    b.analyze(data);
    for(unsigned i = 0; i < 4; i++)
        cout << b.getLoadForCPU(i) << endl;
    return 0;
}
