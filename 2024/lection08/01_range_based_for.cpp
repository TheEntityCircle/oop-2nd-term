#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Все еще длинновато и часто повторяется.
    vector<int> v(10);
    for (auto it = v.begin(); it != v.end(); ++it)
        cin >> *it;

    // Сокращенная запись - range-based for
    for (auto x : v)
        cout << x << " ";
    cout << endl;

    // На auto она не завязана.
    // Вот так без auto, за типом следим сами.
    for (int x : v)
        cout << x << " ";
    cout << endl;

    // Нюанс. х - это копия, а не ссылка.
    // Чтобы сделать модификацию контейнера, нужны ссылки.
    for (auto& x : v)
        x++;

    // Если не хочется копировать (если в векторе не инты, а что-то большое),
    // но и давать доступ на запись не хочется (вдруг сломают),
    // можно сделать const reference.
    for (const auto& x : v)
        cout << x << " ";
    cout << endl;

    return 0;
}
