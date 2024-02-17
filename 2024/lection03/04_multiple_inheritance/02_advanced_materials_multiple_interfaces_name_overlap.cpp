#include<iostream>

using namespace std;

// Некоторый предок #1
class A {
public:
    // Уже есть у него вот такой метод, никуда не деться
    void describe() {
        cout << "I'm A" << endl;
    }
    // А это мы хотим реализовать
    virtual void foo() = 0;
};

// Некоторый предок #2
class B {
public:
    // И у него уже есть такой же метод, причём своя реализация
    void describe() {
        cout << "I'm B" << endl;
    }
    // И это мы хотим реализовать
    virtual void bar() = 0;
};

// Наш класс, который A и B одновременно
class TestClass : public A, public B
{
    void foo() override {}
    void bar() override {}
};

int main()
{
    // Вот так внезапно можно всегда
    TestClass t;

    // А вот так нельзя - неясно, что вызывать
    t.describe();

    // Зато вот так можно
    // (с явным указанием, откуда взять реализацию)
    t.A::describe();
    t.B::describe();

    return 0;
}

