#include <iostream>

using namespace std;

class Stack
{
    private:
        // Максимальный размер стека
        size_t capacity = 0;
        // Текущий размер стека
        size_t size = 0;
        // Содержимое стека
        int* ptr = nullptr;
    public:
        // Конструктор
        Stack(size_t capacity)
        {
            this->capacity = capacity;
            this->ptr = new int[capacity];
        }

        // Деструктор
        ~Stack()
        {
            delete[] ptr;
        }

        // Конструктор копирования
        Stack(const Stack& s)
        {
            cout << "Custom copy constructor called" << endl;
            // Скопируем размер
            capacity = s.capacity;
            size = s.size;
            // Но блок памяти создадим свой!
            ptr = new int[capacity];
            // И скопируем содержимое
            for(size_t i = 0; i < capacity; ++i)
                ptr[i] = s.ptr[i];
        }

        // Возвращает true, если стек пуст
        bool isEmpty() const
        {
            return size == 0;
        }

        // Возвращает true, если стек полностью заполнен
        bool isFull() const
        {
            return size == capacity;
        }

        // Добавляет элемент в стек
        void push(const int& elem)
        {
            ptr[size++] = elem;
        }

        // Извлекает элемент из стека
        int pop()
        {
            return ptr[--size];
        }

        // Дружественная функция для вывода содержимого стека
        friend ostream& operator<<(ostream& os, const Stack& s);
        
};

// Выводит содержимое стека
ostream& operator<<(ostream& os, const Stack& s)
{
    os << "Stack (" << s.size << "/" << s.capacity << "): [";
    for (size_t i = 0; i < s.size; i++)
    {
        os << s.ptr[i];
        if (i != s.size-1)
            os << ", ";
    }
    os << "]";

    return os;
}

int main()
{
    // Объявляем стек
    Stack intStack(10);

    // Заполняем стек
    for (int i = 0; i < 10; i++)
        intStack.push(i);

    // Печатаем содержимое стека
    cout << intStack << endl;

    // Второй стек, создан из первого
    // (используется copy constructor)
    Stack intStack2(intStack);
    cout << intStack2 << endl;

    return 0;
}
