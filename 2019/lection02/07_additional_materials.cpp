#include <iostream>
#include <vector>

using namespace std;

/*
 * Пример использует некоторое количество ещё не рассказанного материала. Но, думаю, при желании код вполне можно прочитать.
 * 
 * В примере есть два класса - ClassA и ClassB. ClassA внутри своего 'умного' конструктора вызывает N раз свой же 'простой' конструктор. 
 * В итоге вроде как создаётся N+1 объектов. Но есть нюанс - все эти N 'дочерних' объектов никак не адресуются 
 * из создавшего их 'родительского' объекта, они тут же выходят из области видимости и уничтожаются.
 *
 * Если в main раскомментить создание classA, то это будет наглядно видно:
 *   ClassA complex constructor called     <== начал работать 'умный' конструктор
 *   ClassA simple constructor called      <== создан первый 'дочерний' объект
 *   ClassA destructor called              <== он тут же уничтожен
 *   ClassA simple constructor called      <== создан второй объект
 *   ClassA destructor called              <== и он тоже уничтожен
 *   ClassA destructor called              <== а вот это уже завершение main-а и уничтожение 'стартового' объекта
 *   
 *   ClassB ведёт себя иначе:
 *   - 'умный' конструктор тоже создаёт объекты, но не на стеке, а в динамической памяти
 *   - сохраняются ссылки на созданные дочерние объекты
 *   - в деструкторе перед удалением самого объекта вызывается удаление всех дочерних
 *
 * Если в main раскомментить создание classB, то это будет наглядно видно:
 *
 *   ClassB complex constructor called     <== начал работать 'умный' конструктор
 *   ClassB simple constructor called      <== создан первый 'дочерний' объект
 *   ClassB simple constructor called      <== создан второй 'дочерний' объект
 *   ClassB destructor called              <== уничтожен первый 'дочерний' объект, вызов его деструктора выполнен из деструктора 'родителя'
 *   ClassB destructor called              <== второй тоже уничтожен
 *   ClassB destructor called              <== уничтожение 'стартового' объекта
 */ 

class TestClassA
{
public:
    TestClassA() {
        cout << "ClassA simple constructor called" << endl;
    }

    TestClassA(int n) {
        cout << "ClassA complex constructor called" << endl;
        for(int i = 0; i < n; i++)
        {
            TestClassA tmp;
        }
    }

    ~TestClassA() {
        cout << "ClassA destructor called" << endl;
    }
};


class TestClassB
{
private:
    vector<TestClassB*> children;

public:
    TestClassB() {
        cout << "ClassB simple constructor called" << endl;
    }

    TestClassB(int n) {
        cout << "ClassB complex constructor called" << endl;
        for(int i = 0; i < n; i++)
        {
            children.push_back(new TestClassB());
        }
    }

    ~TestClassB() {
        cout << "ClassB destructor called" << endl;
        for(unsigned int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

int main()
{
    //TestClassA pa(2);
    //TestClassB pb(2);
    return 0;
}
