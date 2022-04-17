#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

/*
 * Это достаточно сложный пример, затрагивающий тему move semantics.
 * Это очень обширная тема, возникшая из простого вопроса "как не копировать 
 * большие объёмы по памяти при возврате чего-нибудь тяжёлого из функции".
 *
 * В C++98 можно было делать так:
 *
 * Вариант 1: возвращаем указатель, копирования нет, но не забудьте про delete
 * vector<int>* make_big_vector(); 
 * ...
 * vector<int>* result = make_big_vector();
 *
 * Вариант 2: выдача по ссылке, копирования нет, но вызывающему нужен именованный объект
 * void make_big_vector( vector<int>& out );
 * ...
 * vector<int> result;
 * make_big_vector( result );
 *
 * В C++11 можно использовать перенос (move semantics)
 * vector<int> make_big_vector();
 * ...
 * vector<int> result = make_big_vector();
 */

/*
 * Большой обзор по теме: http://thbecker.net/articles/rvalue_references/section_01.html
 * (Внимание! По ссылке 11 страниц, которые надо листать.)
 *
 * И ещё глубже по теме: https://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers
 */

using namespace std;

class Array
{
    private:
        int* ptr = nullptr;
        unsigned int size;

    public:

        Array(): size(0)
        {
            cout << "Empty constructor" << endl;
        }

        // Конструктор с параметром. Создаёт новый массив нужного размера.
        Array(unsigned int size): size(size)
        {
            cout << "Regular constructor" << endl;
            ptr = new int[size];

            for (unsigned int i = 0; i < size; i++)
                ptr[i] = i;
        }

        // Деструктор. Освобождает память.
        ~Array()
        {
            // cout << "Destructor" << endl;
            if (ptr != nullptr)
                delete[] ptr;
        }

        // Копирующий конструктор.
        Array(const Array& that)
        {
            cout << "Copy constructor" << endl;
            size = that.size;
            ptr = new int[size];
            // Внимание! Так можно с int-ами, но нельзя со сложным объектами.
            // У сложных объектов могут быть свои перегруженные операторы.
            memcpy(ptr, that.ptr, that.size*sizeof(int));
        }
        
        // Оператор присваивания.
        const Array& operator=(const Array& that)
        {
            cout << "Operator=(const &)" << endl;
            // Идиома copy-&-swap (!)
            Array tmp(that);
            std::swap(size, tmp.size);
            std::swap(ptr, tmp.ptr);
            return *this;
        }

        // Перемещающий конструктор.
        Array(Array&& that)
        {
            cout << "Move constructor" << endl;
            *this = std::move(that);
        }

        // Оператор перемещения.
        void operator=(Array&& that)
        {
            cout << "Operator=(&&)" << endl;
            std::swap(size, that.size);
            std::swap(ptr, that.ptr);
        }

        // Функция суммирования элементов массива
        int sum() const
        {
            int s = 0;

            for (unsigned int i = 0; i < size; i++)
                s += ptr[i];

            return s;
        }

        // Функция получения элемента массива по индексу
        int operator[](unsigned int i) const
        {
            return ptr[i];
        }
       
        // Функция получения ссылки на элемент массива по индексу
        int& operator[](unsigned int i)
        {
            return ptr[i];
        }
};

Array randomArray(unsigned int size)
{
    Array a(size);

    for (unsigned int i = 0; i < size; i++)
        a[i] = (int)(10.0*rand() / RAND_MAX);

    return a;
}

int main()
{
    cout << "=== Part 1 ===" << endl;

    // Создаём массив при помощи конструктора с параметром 
    cout << "Creating a" << endl;
    Array* a = new Array(20);

    // Создаём массив при помощи конструктора копирования
    cout << "Creating b" << endl;
    Array b(*a);
    
    // Создаём массив при помощи конструктора с параметром 
    cout << "Creating c" << endl;
    Array c(30);

    // Используем оператор присваивания, чтобы скопировать содержимое массива
    cout << "Assigning c" << endl;
    c = *a;
   
    // Выводим сумму элементов массива a
    // cout << "Sum of a is: " << a->sum() << endl;

    // Удаляем массив a
    delete a;

    // Считаем сумму элементов массивов b и c
    // cout << "Sum of b is: " << b.sum() << endl;
    // cout << "Sum of c is: " << c.sum() << endl;

    // Выводим значения элементов с индексом 5 для массивов b и c
    // cout << "b[5]: " << b[5] << endl;
    // cout << "c[5]: " << c[5] << endl;

    // Изменяем значения элементов с индексом 5 для массивов b и c
    // b[5] = 20;
    // c[5] = 30;
    
    // Считаем сумму элементов массивов b и c
    // cout << "Sum of b is: " << b.sum() << endl;
    // cout << "Sum of c is: " << c.sum() << endl;

    // Выводим значения элементов с индексом 5 для массивов b и c
    // cout << "b[5]: " << b[5] << endl;
    // cout << "c[5]: " << c[5] << endl;

    cout << "=== Part 2 ===" << endl;

    Array tmp(30);

    cout << "Creating ref" << endl;
    // Создаём константную ссылку на массив
    const Array& d = tmp;

    // Так нельзя! Ссылка константная, соответственно, по ней может быть вызван только константный метод.
    // d[5] = 50;

    // Вызываем константный метод на константной ссылке на объект
    // cout << "d[5]: " << d[5] << endl;

    // Создаём два массива
    Array e(1), f(2);

    cout << "Assigning e and f" << endl;
    // Используем присвоение «по цепочке».
    e = f = d;
    
    // Считаем сумму элементов массивов b и c
    // cout << "Sum of e is: " << e.sum() << endl;
    // cout << "Sum of f is: " << f.sum() << endl;

    cout << "=== Part 3 ===" << endl;

    Array g(1);
    cout << "Assigning g from tmp object" << endl;
    // Используем семантику переноса при копировании
    g = randomArray(100);
    
    // Считаем сумму элементов массива e
    // cout << "Sum of g is: " << g.sum() << endl;

    cout << "Creating h from tmp object" << endl;
    // Используем семантику переноса при создании объекта
    Array h = randomArray(100);
    
    // Считаем сумму элементов массива g
    // cout << "Sum of h is: " << h.sum() << endl;

    cout << "=== Part 4 ===" << endl;

    vector<Array> v;
    v.reserve(10);  // сравните это с v(10)

    Array i(1);
    v.push_back(i);
    v.push_back(i);
    v.push_back(std::move(i));
    v.push_back(Array(1));


    cout << "=== Part 5 ===" << endl;
    // Эту часть стоит выполнить, закомментировав move constructor и operator
    vector<Array> w;
    w.reserve(10);

    w.push_back(Array(1));
    w.push_back(1);
    w.emplace_back(Array(1));
    w.emplace_back(1);

    return 0;
}
