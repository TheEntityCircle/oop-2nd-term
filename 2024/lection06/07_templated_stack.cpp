#include <iostream>

using namespace std;

// Шаблонный класс стека, для которого можно задавать тип хранимых элементов
template<typename T>
class Stack
{
    private:
        // Максимальный размер стека
        size_t capacity = 0;
        // Текущий размер стека
        size_t size = 0;
        // Содержимое стека
        T* ptr = nullptr;
    public:
        // Конструктор
        Stack(size_t capacity)
        {
            this->capacity = capacity;
            this->ptr = new T[capacity];
        }

        // Деструктор
        ~Stack()
        {
            delete[] ptr;
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
        void push(const T& elem)
        {
            ptr[size++] = elem;
        }

        // Извлекает элемент из стека
        T pop()
        {
            return ptr[--size];
        }

        // Дружественная функция для вывода содержимого стека.
        // Внимание: friend-функция должна тоже быть template-ом.
        template<typename X>
        friend ostream& operator<<(ostream& os, const Stack<X>& s);

        // Сделать вот так и обойтись без template-а нельзя - компилятор будет ругаться.
        // friend ostream& operator<<(ostream& os, const Stack<T>& s);

        // Подробнее про сложности template-ов и friend-ов 
        // на https://isocpp.org/wiki/faq/templates#template-friends
};

// Выводит содержимое стека
template<typename T>
ostream& operator<<(ostream& os, const Stack<T>& s)
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

// Структура
typedef struct
{
    int i;
    char c;
} Struct;

// Выводит содержимое структуры
ostream& operator<<(ostream& os, const Struct& s)
{
    os << "{" << s.i << ", " << s.c << "}";

    return os;
}


int main()
{
    // Стек, содержащий int-ы
    Stack<int> intStack(10);
    // Стек, содержащий char-ы
    Stack<char> charStack(11);
    // Стек, содержащий структуры
    Stack<Struct> structStack(12);

    // Заполняем стеки
    for (int i = 0; i < 10; i++)
    {
        intStack.push(i);
        charStack.push('A'+i);
        structStack.push({i, (char)('A' + i)});
        // Ошибка компиляции
        // structStack.push(i);
        // structStack.push('A' + i);
    }

    // Печатаем содержимое стеков
    cout << intStack << endl;
    cout << charStack << endl;
    cout << structStack << endl;

    // Извлекаем данные из стеков
    for (int i = 0; i < 10; i++)
    {
        cout << intStack.pop() << " " << charStack.pop() << endl;
        Struct st = structStack.pop();
        cout << st.i << " " << st.c << endl;
    }
    
    // Печатаем содержимое стеков
    cout << intStack << endl;
    cout << charStack << endl;
    cout << structStack << endl;

    return 0;
}
