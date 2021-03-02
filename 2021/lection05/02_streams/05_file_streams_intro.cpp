#include <iostream>
#include <fstream>   // Для файловых потоков

using namespace std;

int main()
{
    // Создадим файловый поток вывода (output file stream)
    ofstream outfile;
    // Откроем файл на запись
    outfile.open("test.data");

    // Теперь с ним можно обращаться, как с cout
    for(unsigned int i = 0; i < 10; i++) {
        outfile << i << endl;
    }
    // Закроем поток
    outfile.close();

    // Создадим файловый поток ввода
    ifstream infile;
    // Откроем тот же файл на чтение
    infile.open("test.data");

    // Будем читать поток 'до конца' (файла в данном случае)
    unsigned int a;
    while(infile >> a) { // ~ while(fscanf(...) != EOF)
        cout << "Read from file: " << a << endl;
    }
    // Не забудем закрыть
    infile.close();

    return 0;
}
