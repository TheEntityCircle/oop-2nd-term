#ifndef DICE_H
#define DICE_H

class Dice
{
protected:
    int number_of_faces;
public:
    Dice(int number_of_faces);
    int roll();
};

#endif
