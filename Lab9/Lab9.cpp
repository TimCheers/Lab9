#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//1 Создать текстовый файл F1 не менее, чем из 10 строк и
//записать в него информацию
//2 Выполнить задание.
//1) Скопировать из файла F1 в файл F2 все строки, в которых
//более 2 слов.
//2) Определить номер слова, в котором больше всего гласных
//букв.

int main()
{
    system("chcp 1251>nul");
    ifstream F1("F1.txt");
    ofstream F2("F2.txt");
    string chars = "АаЕеЁёИиОоУуЭэЮюЯя";
    string row;
    int value, numb=0, max;
    while (!F1.eof())
    {
        int k = 0;
        getline(F1, row);
        value = row.length();
        for (int i = 1; i < value; i++)
        {
            if (row[i] == ' ' && row[i - 1] != ' ')
            {
                k++;
            }

        }
        k++;
        if (k > 2)
        {
            F2 << row << endl;
        }

    }
    F1.close();

    




    return 0;
}

