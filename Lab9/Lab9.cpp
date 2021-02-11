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


int CountW(const string row, const int value)
{
    int k = 0;
    int i = 0;
    for (int i = 1; i < value; i++)
    {
        if (row[i] == ' ' && row[i - 1] != ' ')
        {
            k++;
        }
    }
    if (row[value - 1] != ' ')
    {
        k++;
    }
    return k;
}


void separation(string*NewSTR,string row, int k)
{
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        NewSTR[i] = "";
        while (row[j]==' ')
        {
            j++;
        }
        while (row[j]!=' '&& row[j] != '\n'&& row[j] != '\0')
        {
            NewSTR[i] += row[j++];
        }
    }
}

int foo(string *NewSTR, int k, string chars)
{
    int g = 0, num, max = 0;
    for (int i = 0; i < k; i++)                             //итерация по строке (слова в строке)
    {
        for (int j = 0; j < NewSTR[i].length()-1; j++)      //итерация по слову (буквы в слове)
        {
            for (int l = 0; l < 12; l++)                    //сравнение каждой буквы с гласными
            {
                if (NewSTR[i][j]==chars[l])
                {
                    g++;
                }
            }
        }
        if (max < g)
        {
            max = g;
            num = i + 1;
        }
        g = 0;
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
    int value, numMax = 0, k, nums = 0;
    while (!F1.eof())
    {
        getline(F1, row);
        value = row.length();
        k = CountW(row, value);               //количество слов в строке
        string *NewSTR = new string[k];
        separation(NewSTR, row, k);
        numMax = foo(NewSTR, k, chars);
        cout << numMax<<endl;
        if (k > 2)
        {
            F2 << row << endl;
        }
        cout << k << endl;
        for (int i = 0; i < k; i++)
        {
            cout << NewSTR[i]<<"\n";
        }
        cout << endl;
    }
    F1.close();
    F2.close();

    return 0;
}

