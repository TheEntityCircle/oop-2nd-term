#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Array
{
    private:
        int* ptr = nullptr;
        unsigned int size;

    public:
        // Конструктор с параметром. Создаёт массив нужного размера.
        Array(unsigned int size): size(size)
        {
            cout << "Regular constructor" << endl;
            ptr = new int[size];

            for (unsigned int i = 0; i < size; i++)
                ptr[i] = i;
        }

        // Копирующий конструктор. Создаёт копию передаваемого объекта.
        Array(const Array& that)
        {
            cout << "Copy constructor" << endl;
            *this = that;
        }
        
        // Копирующий конструктор с переносом. Создаёт копию передаваемого объекта, «перенося» его содержимое.
        Array(Array&& that)
        {
            cout << "Move constructor" << endl;
            *this = that;
        }


        // Оператор присваивания. Изменяет содержимое объекта, делая его копией переданного объекта.
        const Array& operator=(const Array& that)
        {
            cout << "Operator=(const &)" << endl;
            delete[] ptr;

            size = that.size;

            ptr = new int[size];
            memcpy(ptr, that.ptr, size*sizeof(int));

            return *this;
        }
        
        // Оператор присваивания с переносом. Изменяет содержимое объекта, «перенося» содержимое другого объекта.
        void operator=(Array&& that)
        {
            cout << "Operator=(&&)" << endl;
            delete[] ptr;

            size = that.size;

            ptr = that.ptr;

            that.ptr = nullptr;
        }

        // Деструктор. Освобождает память.
        ~Array()
        {
            cout << "Destructor" << endl;
            delete[] ptr;
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
    cout << "Sum of a is: " << a->sum() << endl;

    // Удаляем массив a
    delete a;

    // Считаем сумму элементов массивов b и c
    cout << "Sum of b is: " << b.sum() << endl;
    cout << "Sum of c is: " << c.sum() << endl;

    // Выводим значения элементов с индексом 5 для массивов b и c
    cout << "b[5]: " << b[5] << endl;
    cout << "c[5]: " << c[5] << endl;

    // Изменяем значения элементов с индексом 5 для массивов b и c
    b[5] = 20;
    c[5] = 30;
    
    // Считаем сумму элементов массивов b и c
    cout << "Sum of b is: " << b.sum() << endl;
    cout << "Sum of c is: " << c.sum() << endl;

    // Выводим значения элементов с индексом 5 для массивов b и c
    cout << "b[5]: " << b[5] << endl;
    cout << "c[5]: " << c[5] << endl;

    cout << "=== Part 2 ===" << endl;

    Array tmp(30);

    cout << "Creating ref" << endl;
    // Создаём константную ссылку на массив
    const Array& d = tmp;

    // Так нельзя! Ссылка константная, соответственно, по ней может быть вызван только константный метод.
    // d[5] = 50;

    // Вызываем константный метод на константной ссылке на объект
    cout << "d[5]: " << d[5] << endl;

    // Создаём два массива
    Array e(1), f(2);

    cout << "Assigning e and f" << endl;
    // Используем присвоение «по цепочке».
    e = f = d;
    
    // Считаем сумму элементов массивов b и c
    cout << "Sum of e is: " << e.sum() << endl;
    cout << "Sum of f is: " << f.sum() << endl;

    cout << "=== Part 3 ===" << endl;

    Array g(1);
    cout << "Assigning g from tmp object" << endl;
    // Используем семантику переноса при копировании
    g = randomArray(100);
    
    // Считаем сумму элементов массива e
    cout << "Sum of g is: " << g.sum() << endl;

    cout << "Creating h from tmp object" << endl;
    // Используем семантику переноса при создании объекта
    Array h = randomArray(100);
    
    // Считаем сумму элементов массива g
    cout << "Sum of h is: " << h.sum() << endl;

    return 0;
}
