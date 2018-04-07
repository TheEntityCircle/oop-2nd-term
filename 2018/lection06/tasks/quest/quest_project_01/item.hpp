#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using std::string;

// Класс предмета
class Item {
protected:
    string title;
    int weight;
    int level;
    bool magical;

public:
    // Так можно создать предмет, указав его название, вес, уровень и магичность
    Item(string title, int weight, int level, bool magical);

    // Получить вес предмета
    int getWeight();

    // Получить уровень предмета
    int getLevel();

    // Получить, является ли предмет магичным
    int isMagical();
};

#endif
