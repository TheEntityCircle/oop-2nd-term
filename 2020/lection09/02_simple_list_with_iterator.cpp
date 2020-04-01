#include <iostream>
#include <iterator>
#include <algorithm>
  
using namespace std;

// Отдельный элемент списка
class ListElement {
    friend class SimpleList;
    friend class SimpleListIterator;

    ListElement(int value) : value(value), next(nullptr) {
    }

private:
    int value;         // Значение
    ListElement* next; // Указатель на следующий элемент
};


/*
 * Реализация итератора
 */
class SimpleListIterator {
public:
    /*
     * Служебные поля, метаданные итератора
     */

    // Вид итератора
    // (что конкретно мы намерены реализовать)
    using iterator_category = std::forward_iterator_tag;

    // Типы значения, указателя на значение, референса на значение
    // (связаны между собой, зависят от контейнера, могут быть шаблонизированы)
    using value_type = int;
    using pointer = int*;
    using reference = int&;

    // Тип вычитания двух итераторов
    // (это не требуется менять примерно никогда)
    using difference_type = std::ptrdiff_t;

    // Конструкторы
    SimpleListIterator() : p(nullptr) {
    }

    SimpleListIterator(ListElement* el) : p(el) {
    }

    // Разыменование, получение значения
    // TODO: обработка *list.end() и аналогов
    reference operator*() const {
        return p->value;
    }

    // Инкременты итератора
    // (логически -- переход к следующему значению)
    // TODO: обработка list.end()++ и аналогов

    SimpleListIterator& operator++() {
        p = p->next;
        return *this;
    }

    SimpleListIterator operator++(int) {
        SimpleListIterator resp = *this;
        p = p->next;
        return resp;
    }

    // Сравнение *итераторов*
    // (т.е. сравниваем адреса, не значения по адресам)

    bool operator==(const SimpleListIterator& it) const {
        return p == it.p;
    }
    bool operator!=(const SimpleListIterator& it) const {
        return !(*this == it);
    }

private:
    // Указатель на текущий элемент
    ListElement *p;
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

    /*
     * API для внешнего кода
     */

    // Добавление нового элемента в список
    void insert(int value);
    // Вернуть размер списка
    unsigned int size() const;

    /*
     * Реализация итератора
     */

    // Говорим, что итератором является класс SimpleListIterator
    // (чтобы было можно сказать SimpleList::iterator s = ...)
    using iterator = SimpleListIterator;

    // Контейнер должен уметь отдавать служебные итераторы:
    // - на первый элемент;
    iterator begin() const;
    // - на позицию "после последнего элемента".
    iterator end() const;

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

// Сколько всего сейчас элементов в списке
unsigned int SimpleList::size() const {
    return n;
}

// Итератор на первый элемент в контейнере
SimpleListIterator SimpleList::begin() const {
    return SimpleListIterator(root);
}

// Итератор на позицию "после последнего элемента"
SimpleListIterator SimpleList::end() const {
    return SimpleListIterator(nullptr);
}


int main()
{
    SimpleList list;

    for(unsigned int i = 1; i < 10; i++)
        list.insert(i*i);

    for(SimpleList::iterator it = list.begin(); it != list.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "STL count result: " << count(list.begin(), list.end(), 25) << endl;

    return 0;
}
