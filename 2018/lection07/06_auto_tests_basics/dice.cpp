#include "dice.hpp"
#include <stdlib.h> 
#include <time.h>

Dice::Dice(int number_of_faces)
{
    srand (time(NULL));
    this->number_of_faces = number_of_faces;
}

int Dice::roll()
{
    return rand() % this->number_of_faces;
}
