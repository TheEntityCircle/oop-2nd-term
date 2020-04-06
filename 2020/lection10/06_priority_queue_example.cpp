#include <iostream>
#include <random>
#include <queue>

using namespace std;

// Класс "мячик в 3D"
class Ball
{
friend ostream& operator<<(ostream& os, const Ball& p);
private:
    // Координаты
    double x, y, z;
    // Масса
    double m;

public:
    // Конструктор
    Ball(double x, double y, double z, double m) : x(x), y(y), z(z), m(m) {
    }

    // Допустим, мы сравниваем мячики в смысле
    // "кто ближе к началу координат"
    // (хотя это и несколько странно)
    bool operator<(const Ball& b) const {
        double sqr_dist1 = x * x + y * y + z * z;
        double sqr_dist2 = b.x * b.x + b.y * b.y + b.z * b.z;
        return sqr_dist1 < sqr_dist2;
    }

    double getX() const {
        return x;
    }

    double getY() const {
        return y;
    }

    double getZ() const {
        return z;
    }

    double getM() const {
        return m;
    }
};

// Оператор вывода точки
ostream& operator<<(ostream& os, const Ball& p) {
    os << "Coords = {" << p.x << "; " << p.y << "; " << p.z << "} Mass = " << p.m;
    return os;
};


// Функтор, сравнивает мячики по массе
class CustomCompareByMass
{
public:
    bool operator()(const Ball& a, const Ball& b) const
    {
        return a.getM() < b.getM();
    }
};


int main()
{
    // Сколько точек у нас будет
    const int N = 10;

    // Инициализация генерации случайных чисел
    double lower_bound = 0;
    double upper_bound = 1;
    std::uniform_real_distribution<double> uniform_dist(lower_bound, upper_bound);
    std::default_random_engine random_engine;

    // Создадим очередь с приоритетами.
    // Создание "по умолчанию", т.е. хранение в контейнере по умолчанию, 
    // приоритет определяется оператором сравнения объектов.
    priority_queue<Ball> q1;

    // Ещё одна очередь, теперь не по умолчанию.
    // Приоритет определяется переданным функтором.
    priority_queue<Ball, vector<Ball>, CustomCompareByMass> q2;

    // Сгенерим и запушим случайные точки
    double scale = 1;
    for (int i = 0; i < N; ++i) {
        double x = uniform_dist(random_engine) * scale;
        double y = uniform_dist(random_engine) * scale;
        double z = uniform_dist(random_engine) * scale;
        double m = uniform_dist(random_engine);
        Ball random_point(x, y, z, m);
        q1.push(random_point);
        q2.push(random_point);
        scale *= 10;
    }

    // Посмотрим содержимое очередей

    cout << "===== Default queue data: " << endl;
    for (int i = 0; i < N; ++i) {
        cout << q1.top() << endl;
        q1.pop();
    }

    cout << "===== Custom queue data: " << endl;
    for (int i = 0; i < N; ++i) {
        cout << q2.top() << endl;
        q2.pop();
    }
 
    return 0;
}

