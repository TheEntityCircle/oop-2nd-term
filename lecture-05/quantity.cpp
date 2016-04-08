#include <iostream>

using namespace std;

// Шаблонный класс для размерной величины
template<int L, int M, int T, int I, int Theta, int N, int J>
class DimQ
{
    public:
        double value;

        DimQ(double value): value(value) {}
};

// Псевдонимы типов
typedef DimQ<1, 0, 0, 0, 0, 0, 0> Length;
typedef DimQ<0, 1, 0, 0, 0, 0, 0> Mass;
typedef DimQ<0, 0, 1, 0, 0, 0, 0> Time;
typedef DimQ<0, 0, 0, 1, 0, 0, 0> Current;
typedef DimQ<0, 0, 0, 0, 1, 0, 0> Temperature;
typedef DimQ<0, 0, 0, 0, 0, 1, 0> Amount;
typedef DimQ<0, 0, 0, 0, 0, 0, 1> Luminosity;

typedef DimQ<1, 0, -1, 0, 0, 0, 0> Velocity;
typedef DimQ<1, 0, -2, 0, 0, 0, 0> Acceleration;

typedef DimQ<0, 0, 0, 0, 0, 0, 0> Dimensionless;


// Шаблонный оператор изменения знака
template<int L, int M, int T, int I, int Theta, int N, int J>
DimQ<L, M, T, I, Theta, N, J> operator-(const DimQ<L, M, T, I, Theta, N, J>& q)
{
    return DimQ<L, M, T, I, Theta, N, J>(-q.value);
}

// Шаблонный оператор сложения
template<int L, int M, int T, int I, int Theta, int N, int J>
DimQ<L, M, T, I, Theta, N, J> operator+(const DimQ<L, M, T, I, Theta, N, J>& q1, const DimQ<L, M, T, I, Theta, N, J>& q2)
{
    return DimQ<L, M, T, I, Theta, N, J>(q1.value + q2.value);
}

// Шаблонный оператор вычитания
template<int L, int M, int T, int I, int Theta, int N, int J>
DimQ<L, M, T, I, Theta, N, J> operator-(const DimQ<L, M, T, I, Theta, N, J>& q1, const DimQ<L, M, T, I, Theta, N, J>& q2)
{
    return DimQ<L, M, T, I, Theta, N, J>(q1.value - q2.value);
}

// Шаблонный оператор умножения
template<
    int L1, int M1, int T1, int I1, int Theta1, int N1, int J1,
    int L2, int M2, int T2, int I2, int Theta2, int N2, int J2>
DimQ<L1+L2, M1+M2, T1+T2, I1+I2, Theta1+Theta2, N1+N2, J1+J2> operator*(const DimQ<L1, M1, T1, I1, Theta1, N1, J1>& q1, const DimQ<L2, M2, T2, I2, Theta2, N2, J2>& q2)
{
    return DimQ<L1+L2, M1+M2, T1+T2, I1+I2, Theta1+Theta2, N1+N2, J1+J2>(q1.value * q2.value);
}

// Шаблонный оператор деления
template<
    int L1, int M1, int T1, int I1, int Theta1, int N1, int J1,
    int L2, int M2, int T2, int I2, int Theta2, int N2, int J2>
DimQ<L1-L2, M1-M2, T1-T2, I1-I2, Theta1-Theta2, N1-N2, J1-J2> operator/(const DimQ<L1, M1, T1, I1, Theta1, N1, J1>& q1, const DimQ<L2, M2, T2, I2, Theta2, N2, J2>& q2)
{
    return DimQ<L1-L2, M1-M2, T1-T2, I1-I2, Theta1-Theta2, N1-N2, J1-J2>(q1.value / q2.value);
}

// Оператор вывода безразмерной величины
ostream& operator<<(ostream& os, const Dimensionless& v)
{
    os << v.value;

    return os;
}

// Оператор вывода скорости
ostream& operator<<(ostream& os, const Velocity& v)
{
    os << v.value << " m/s";

    return os;
}

// Оператор вывода ускорения
ostream& operator<<(ostream& os, const Acceleration& v)
{
    os << v.value << " m/s^2";

    return os;
}

// Шаблонный оператор вывода размерной величины
template<int L, int M, int T, int I, int Theta, int N, int J>
ostream& operator<<(ostream& os, const DimQ<L, M, T, I, Theta, N, J>& q)
{
    os << q.value << " ";

    if (L != 0)
        os << "m^(" << L << ")";
    
    if (M != 0)
        os << "kg^(" << M << ")";
    
    if (T != 0)
        os << "s^(" << T << ")";
    
    if (I != 0)
        os << "A^(" << I << ")";
    
    if (Theta != 0)
        os << "K^(" << Theta << ")";
    
    if (N != 0)
        os << "mol^(" << N << ")";
    
    if (J != 0)
        os << "cd^(" << J  << ")";

    return os;

}

int main()
{
    // Длина
    Length l = {100};
    // Время    
    Time t = {20};

    // Скорость
    Velocity v = l / t;

    // Ускорение
    Acceleration a = v / t;

    // Размерная величина
    auto smth = v*a*a/t;
    // Безразмерная величина
    auto dimensionless = v/v;

    // Выводим величины
    cout << v << endl;
    cout << a << endl;
    cout << smth << endl;
    cout << dimensionless << endl;

    // Ошибка компиляции!
    // Dimensionless d = v;
    // Mass m = v;
    // Amount a = d;

    return 0;
}
