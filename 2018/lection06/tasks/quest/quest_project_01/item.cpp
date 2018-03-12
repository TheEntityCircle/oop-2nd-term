#include "item.hpp"

// Так можно создать предмет, указав его название, вес, уровень и магичность
Item::Item(string title, int weight, int level, bool magical) {
    this->title = title;
    this->weight = weight;
    this->level = level;
    this->magical = magical;
}

// Получить вес предмета
int Item::getWeight() {
    return this->weight;
}

// Получить уровень предмета
int Item::getLevel() {
    return this->level;
}

// Получить, является ли предмет магичным
int Item::isMagical() {
    return this->magical;
}
