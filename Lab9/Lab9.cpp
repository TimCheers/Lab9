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
    setlocale(LC_ALL, "ru");
    ifstream F1("F1.txt");
    ofstream F2("F2.txt");
    string chars = "AaEeIiUuYyOo";
    string row;
    int value, num = 0, max, g = 0, namMax;
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
            if (row[i] != ' ' && row[i + 1] == ' ')
            {
                num++;
            }
            if (row[i]!=' ')
            {
                for (int j = 0; j < 12; j++)
                {
                    if (row[i]==chars[j])
                    {
                        g++;
                    }
                }
            }
        }
        k++;
        if (row[value-1]!=' ')
        {
            num++;
        }
        if (k > 2)
        {
            F2 << row << endl;
        }

    }
    F1.close();

    cout << num;

    return 0;
}

