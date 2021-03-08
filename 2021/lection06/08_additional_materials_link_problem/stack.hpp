#include <iostream>

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
        Stack(size_t capacity);

        // Деструктор
        ~Stack();

        // Возвращает true, если стек пуст
        bool isEmpty() const;

        // Возвращает true, если стек полностью заполнен
        bool isFull() const;

        // Добавляет элемент в стек
        void push(const T& elem);

        // Извлекает элемент из стека
        T pop();
};
