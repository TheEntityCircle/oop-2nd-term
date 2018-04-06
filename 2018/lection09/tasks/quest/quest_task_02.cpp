#include <iostream>

using namespace std;

// Класс предмета
class Item {
protected:
    string title;
    int weight;
    int level;
    bool magical;

public:
    // Так можно создать предмет, указав его название, вес, уровень и магичность
    Item(string title, int weight, int level, bool magical) {
        this->title = title;
        this->weight = weight;
        this->level = level;
        this->magical = magical;
    }

    // Получить вес предмета
    int getWeight() const {
        return this->weight;
    }

    // Получить уровень предмета
    int getLevel() const {
        return this->level;
    }

    // Получить, является ли предмет магичным
    int isMagical() const {
        return this->magical;
    }
};

// Базовый класс героя
class Player {
protected:
    // Сила и уровень героя
    int strength;
    int level;

public:
    // Создать героя, все подробности будут указаны позже
    Player() { }
    // Удалить героя, ничего умного эта процедура пока что не требует
    virtual ~Player() { }

    // Базовые методы, пока что очень простые.
    // На данном этапе можно считать, что для всех героев они ведут себя одинаково, 
    // так что пусть будут в базовом классе.

    // Задать силу
    void setStrength(int strength) {
        this->strength = strength;
    }
    // Задать уровень
    void setLevel(int level) {
        this->level = level;
    }

    // Получить силу
    int getStrength() const {
        return this->strength;
    }
    // Получить уровень
    int getLevel() const {
        return this->level;
    }

    // Проверка, может ли игрок использовать предмет
    virtual bool canUse(Item* item) const = 0;

    // Может ли игрок колдовать, зависит от конкретного класса игрока
    virtual bool canCast() const = 0;

    // Проверка, может ли игрок лечить других игроков.
    // Лечить умеет или любой волшебник, или 
    // игрок достаточно высокого уровня.
    bool canHeal() const {
        return canCast() || getLevel() > 10;
    }
};


// TODO: здесь реализуйте классы Knight и Wizard

// Заглушка, имитирует техническую сторону будущего движка
int main()
{
    Player* players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);

    for(int i = 0; i < 2; i++) {
        cout << "Can heal: " << players[i]->canHeal() << endl;
    }

    return 0;
}
