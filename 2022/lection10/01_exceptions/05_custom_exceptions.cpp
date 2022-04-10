#include <iostream>
#include <stdexcept>

using namespace std;

// Опишем свой новый логический exception
class LazyException : public std::runtime_error
{
public:
    LazyException() : std::runtime_error("I'm just too lazy today") { }
};

void func1()
{
    // Делаем вид, что всё сломалось.
    // Есть разные варианты, как именно сломалось.

    //throw LazyException();
    throw runtime_error("Network is not available! Can not proceed.");
}

void func2()
{
    func1();
}

void func3()
{
    func2();
}


int main()
{
    // Happy path -- штатный режим работы
    try {
        // Вызов func3
        func3();

        // Ещё какие-то операции дальше

    // Обработка известной нам возможной логической проблемы
    } catch (const LazyException& e) {
        cerr << "Damned function is lazy now. Requires special handling." << endl;
        return -1;
    // Реакция по умолчанию на все прочие мыслимые проблемы
    } catch (const exception& e) {
        cerr << "We failed! And something real happened this time!" << endl;
        cerr << "Failure reason: " << e.what() << endl;
        return -1;
    }

    return 0;
}
