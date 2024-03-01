#include <iostream>
using namespace std;

class Horse {
    int horseshoes;
public:
    Horse();
    Horse(int horseshoes);
    void talk();
};

class Flying {
    bool wings;
    bool engines;
    double velocity;
public:
    Flying(bool wings, bool engines, double velocity);
    double getVelocity();
};

class Pegasus : public Horse, public Flying {
    bool domesticated;
    int gold;
public:
    // Pegasus(bool domesticated) : Horse(0), Flying(true, false, 200.0), domesticated(domesticated), gold(200) {}
    Pegasus(bool domesticated) : domesticated(domesticated), Flying(true, false, 200.0) {}
    Pegasus() : Horse(0), Pegasus(false) {}
};


    // Вначале конструкторы предков, потом инициализация полей

    // Так нельзя - будет видно с флагом -Wall
    // Pegasus(bool domesticated) : domesticated(domesticated), Flying(true, false, 200.0), gold(200), Horse(0) {}

    // И так тоже - порядок предков не тот
    // Pegasus(bool domesticated) : Flying(true, false, 200.0), Horse(0), domesticated(domesticated), gold(200) {}

    // Так максимально правильно и по порядку

//    Pegasus(bool domesticated) : domesticated(domesticated), Flying(true, false, 200.0) {}
//    Pegasus() : Pegasus(false), Horse(0) {}    
//};

Horse::Horse(int horseshoes) : horseshoes(horseshoes) {}
Horse::Horse() : Horse(4) {}

void Horse::talk()
{
    cout << "Neigh neigh." << endl;
}

Flying::Flying(bool wings, bool engines, double velocity) : wings(wings), engines(engines), velocity(velocity) {}

double Flying::getVelocity()
{
    return velocity;
}

int main()
{
    return 0;
}
