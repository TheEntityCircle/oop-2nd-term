#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>

using namespace std;

// Отладочный аллокатор с cppreference
template<class Tp>
struct NAlloc
{
    // Вместо вывода на экран мы считаем ёмкость в статическом поле 
    static unsigned long long total_allocated;

    typedef Tp value_type;
 
    NAlloc() = default;
 
    template<class T> NAlloc(const NAlloc<T>&) {}
 
    Tp* allocate(std::size_t n)
    {
        n *= sizeof(Tp);
        // std::cout << "allocating " << n << " bytes\n";
        total_allocated += n;
        return static_cast<Tp*>(::operator new(n));
    }
 
    void deallocate(Tp* p, std::size_t n)
    {
        // std::cout << "deallocating " << n*sizeof*p << " bytes\n";
        total_allocated -= n;
        ::operator delete(p);
    }
};
template<class T, class U>
bool operator==(const NAlloc<T>&, const NAlloc<U>&) { return true; }
template<class T, class U>
bool operator!=(const NAlloc<T>&, const NAlloc<U>&) { return false; }

template<class Tp>
unsigned long long NAlloc<Tp>::total_allocated = 0;

int main()
{
    // Создаём деку
    deque<int, NAlloc<int>> d;

    // Задаём количество элементов
    int n;
    cin >> n;

    // А вот такого у деки нет, как и явно выводимого capacity
    // Для этого мы и притащили отладочный аллокатор
    // d.reserve(n);

    cout << "size: " << d.size() << ", " << "total_allocated: " << NAlloc<int>::total_allocated/sizeof(int) << endl;

    // Заполняем деку
    for (int i = 0; i < n; i++)
    {
        // Попробуйте поменять push_back на push_front и посмотреть, что получится на графике
        d.push_back(i);
        cout << "size: " << d.size() << ", " << "total_allocated: " << NAlloc<int>::total_allocated/sizeof(int) << endl;
   }

    return 0;
}
