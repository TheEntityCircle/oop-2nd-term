#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>

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
            // Это функция из С, оч быстро копирует
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
        friend ostream& operator<<(ostream& os, const Array& s);

};

// Выводит содержимое массива
ostream& operator<<(ostream& os, const Array& s)
{
    os << "Array (" << s.size << "): [";
    for (size_t i = 0; i < s.size; i++)
    {
        os << s[i];
        if (i != s.size-1)
            os << ", ";
    }
    os << "]";

    return os;
}

Array randomArray(unsigned int size)
{
    Array a(size);

    for (unsigned int i = 0; i < size; i++)
        a[i] = (int)(10.0*rand() / RAND_MAX);

    return a;
}

int main()
{
    Array a(20);
    a[5] = 100500;
    cout << "a initial: " << a << endl;
    Array b(a);
    cout << "a after copy:   " << a << endl;
    cout << "b made as copy: " << b << endl;
    Array c(move(a));
    // a остался не просто пустым - он теперь сломан
    // В его полях лежат неинициализированные данные, 
    // которые лежали в с до его инциализации 
    // Если раскомментируете - будет сегфолт
    // cout << "a after move:   " << a << endl;
    cout << "b just in case: " << b << endl;
    cout << "c made as move: " << c << endl;
    return 0;
}
