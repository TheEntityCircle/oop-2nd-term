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
            cout << "Constructor called" << endl;
            this->capacity = capacity;
            this->ptr = new int[capacity];
        }

        // Деструктор
        ~Stack()
        {
            cout << "Destructor called" << endl;
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

        // Оператор присваивания
        Stack& operator = (const Stack &s)
        {
            cout << "Custom assignment operator called" << endl;
            // Очистим нынешнй блок памяти
            delete[] ptr;
            // Пересоздадимся из переданного образца
            capacity = s.capacity;
            size = s.size;
            ptr = new int[capacity];
            for(size_t i = 0; i < capacity; ++i)
                ptr[i] = s.ptr[i];
            return *this;
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

    // Создали отдельный стек
    Stack intStack2(10);
    cout << intStack2 << endl;

    // Передумали, теперь он равен первому
    intStack2 = intStack;
    cout << intStack2 << endl;

    return 0;
}
