#include <iostream>
  
using namespace std;

// Отдельный элемент списка
class ListElement {
    friend class SimpleList;

    ListElement(int value) : value(value), next(nullptr) {
    }

private:
    int value;         // Значение
    ListElement* next; // Указатель на следующий элемент
};

// Сам список целиком
class SimpleList
{
public:
    // У нас будут конструктор и деструктор
    SimpleList();
    ~SimpleList();

    // Явным образом скажем, что разные вариации 
    // копирования и перемещения запрещены
    // (чтобы не писать их в данном примере)
    SimpleList(const SimpleList&) = delete;
    SimpleList(SimpleList&&) = delete;
    SimpleList& operator=(const SimpleList&) = delete;
    SimpleList& operator=(SimpleList&&) = delete;

    // API для внешнего кода
    void insert(int value);
    unsigned int size() const;

private:
    ListElement* root; // Корень списка
    unsigned int n;    // Количество элементов в списке
};

// Конструктор, инициализирует пустой список
SimpleList::SimpleList() : root(nullptr), n(0) {
};

// Деструктор, проходит по списку, удаляя все элементы
SimpleList::~SimpleList() {
    ListElement* cur = root;
    while(cur != nullptr)
    {
        ListElement* next = cur->next;
        delete cur;
        cur = next;
    }
};

// Вставка элемента в список
void SimpleList::insert(int value) {
    // Создали элемент физически
    ListElement* elem = new ListElement(value);

    // Вставили в список
    if(root == nullptr) {
        root = elem;
    } else {
        elem->next = root->next;
        root->next = elem;
    }

    // Увеличили счётчик, сколько всего сейчас элементов в списке
    n++;
}

// Ответ, сколько всего сейчас элементов в списке
unsigned int SimpleList::size() const {
    return n;
}


int main()
{
    SimpleList list;

    for(int i = 1; i < 10; i++)
        list.insert(i*i);

    return 0;
}
