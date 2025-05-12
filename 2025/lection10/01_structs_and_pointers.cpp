#include <iostream>
using namespace std;

struct simple_structure {
    int a, b;
};

struct structure_with_array {
    int a, b;
    int array[5];
};

struct structure_with_pointer {
    int a, b;
    int *p;
};

int main()
{
    simple_structure ss1 = {1, 2};
    simple_structure ss2;
    ss2 = ss1;  // Скопировалось побайтово
    ss1.b = 12; // Чтобы убедиться, что именно скопировалось,
                // и ss2 теперь независимая переменная, 
                // меняем значение оригинала.
    cout << "this is ss2: " << ss2.a << " " << ss2.b << endl;
    ss1.b = 2; // Вернем обратно для простоты расшифровки лога

    simple_structure ss3(ss1); // Технически немного другое,
                               // но тоже копия побайтово
    ss1.b = 23;
    cout << "this is ss3: " << ss3.a << " " << ss3.b << endl;

    structure_with_array sa1 = {2, 3, {0, 1, 2, 3, 4}};
    structure_with_array sa2;
    sa2 = sa1; // Статический массив тоже копируется побайтово
    sa1.array[3] = 100500; // Снова изменим оригинал
    cout << "this is sa2: " << sa2.a << " " << sa2.b << " { ";
    for (auto i : sa2.array) // Это приехало из другого кодстайла,
        cout << i << " ";    // но вообще-то сработает
    cout << "}" << endl;
    sa1.array[3] = 3;  // Вернем обратно для простоты расшифровки лога

    structure_with_array sa3(sa1); // И снова то же через конструктор
    sa1.array[3] = 200600; // Снова изменим оригинал
    cout << "this is sa3: " << sa3.a << " " << sa3.b << " { ";
    for (auto i : sa3.array) // Сработает так же
        cout << i << " ";    
    cout << "}" << endl;

    structure_with_pointer sp1 = {3, 4, new int[5]};
    int cur = 0;          
    // for (auto &i : sp1.p)  // Было бы удобно
    //    i = cur++;          // Но не сработает
    for (auto i = sp1.p; i < sp1.p + 5; ++i)
        *i = cur++;           // Надо или так, или как обычно, через индексы

    structure_with_pointer sp2;
    sp2 = sp1;  // А вот тут скопируется указатель, но не содержимое массива
    sp1.p[3] = 239; // Изменится и в оригинале, и в копии
    cout << "this is sp2: " << sp2.a << " " << sp2.b << " { ";
    for (int i = 0; i < 5; i++) 
        cout << sp2.p[i] << " ";
    cout << "}" << endl;
    sp1.p[3] = 3; // Вернем обратно для простоты расшифровки лога

    structure_with_pointer sp3(sp1); // Как вы уже поняли, сработает аналогично
    sp1.p[3] = 478; // Изменится и в оригинале, и во всех копиях
    cout << "this is sp3: " << sp3.a << " " << sp3.b << " { ";
    for (int i = 0; i < 5; i++)
        cout << sp3.p[i] << " ";
    cout << "}" << endl;

    cout << "adresses of p: " << sp1.p << " " << sp2.p << " " << sp3.p << endl;

    return 0;
}
