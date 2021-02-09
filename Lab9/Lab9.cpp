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

int foo(string chars, string row, int value)
{
    int g = 0, max = 0, num = 0, N = 0;
    for (int i = 0; i < value; i++)
    {
        if (row[i]!=' ')
        {
            for (int j = 0; j < 13; j++)
            {
                if (row[i]==chars[j])
                {
                    g++;
                }
            }
        }
        else
        {
            N++;
            if (max<g)
            {
                max = g;
                num = N;
            }
        }
    }
    return num;
}



int main()
{
    system("chcp 1251>nul");
    setlocale(LC_ALL, "ru");
    ifstream F1("F1.txt");
    ofstream F2("F2.txt");
    string chars = "AaEeIiUuYyOo";
    string row;
    int value, max=0, g = 0, numMax=0, k;
    while (!F1.eof())
    {
        k = 0;
        getline(F1, row);
        value = row.length();
        for (int i = 0; i < value; i++)
        {
            if (row[i] != ' ')
            {
                for (int j = 0; j < 13; j++)
                {
                    if (row[i] == chars[j])
                    {
                        g++;
                    }
                }
            }
            else
            {
                N++;
                if (max < g)
                {
                    max = g;
                    num = N;
                }
            }
        }
        for (int i = 0; i < value; i++)
        {
            if (row[i] == ' ' && row[i - 1] != ' ')
            {
                k++;
            }
        }
        if (row[value-1]!=' ')
        {
            k++;
        }
        if (k > 2)
        {
            F2 << row << endl;
        }
        cout << k << endl;
    }
    F1.close();
    F2.close();

    return 0;
}

