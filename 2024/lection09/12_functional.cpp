#include <functional>
#include <iostream>
#include <vector>

using namespace std; 

// Метод в структуре/классе
struct Printer
{
    Printer(int num) : num_(num) {}
    void print_add(int a) const { cout << num_ + a << " <- method\n"; }
    int num_;
};
 
// Просто функция
void print_num(int i)
{
    cout << i << " <- function\n";
}
 
// Функтор
struct PrintNum
{
    void operator()(int i) const
    {
        cout << i << " <- functor\n";
    }
};

int main()
{
    function<void(int)> f_lambda = [](int a) { cout << a << " <- lambda\n"; };
    function<void(int)> f_function = print_num;
    function<void(int)> f_functor = PrintNum();
    vector<function<void(int)>> vf = {f_lambda, f_function, f_functor};

    std::function<void(const Printer&, int)> f_method_pure = &Printer::print_add; 
    Printer dummy_printer(666);
    std::function<void(int)> f_method_func = std::bind(&Printer::print_add, &dummy_printer, placeholders::_1);
    vf.push_back(f_method_func);

    for (auto f : vf)
        f(239);

    return 0;
}
