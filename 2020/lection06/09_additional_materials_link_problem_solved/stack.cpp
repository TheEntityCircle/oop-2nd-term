#include "stack.hpp"

// Конструктор
template<typename T>
Stack<T>::Stack(size_t capacity)
{
    this->capacity = capacity;
    this->ptr = new T[capacity];
}

// Деструктор
template<typename T>
Stack<T>::~Stack()
{
    delete[] ptr;
}

// Возвращает true, если стек пуст
template<typename T>
bool Stack<T>::isEmpty() const
{
    return size == 0;
}

// Возвращает true, если стек полностью заполнен
template<typename T>
bool Stack<T>::isFull() const
{
    return size == capacity;
}

// Добавляет элемент в стек
template<typename T>
void Stack<T>::push(const T& elem)
{
    ptr[size++] = elem;
}

// Извлекает элемент из стека
template<typename T>
T Stack<T>::pop()
{
    return ptr[--size];
}

// Какие stack-и нам нужны
template class Stack<int>;
template class Stack<char>;
