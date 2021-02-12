#include <iostream>
#include <fstream>
#include <string>
using namespace std;
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
int foo(string *NewSTR, int k, string chars, int &max)
{
    int  num, g;
    for (int i = 0; i < k; i++)                             //итерация по строке (слова в строке)
    {
        g = 0;
        for (int j = 0; j < NewSTR[i].length(); j++)        //итерация по слову (буквы в слове)
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
    int value, numMax = 0, k, num = 0, kol=0, g, gp=0;
    if (F1.is_open())
    {
        while (!F1.eof())
        {
            getline(F1, row);
            value = row.length();
            k = CountW(row, value);               //количество слов в строке
            string* NewSTR = new string[k];
            separation(NewSTR, row, k);
            numMax = foo(NewSTR, k, chars, g);
            if (gp < g)
            {
                num = numMax + kol;
                gp = g;
            }
            if (k > 2)
            {
                F2 << row << endl;
            }
            kol += k;
            g = 0;
        }
        cout << "Номер слова, в котором больше всего гласных букв: " << num << endl;
    }
    else
    {
        cout << "Ошибка при открытии файла F1" << endl;
    }
    F1.close();
    F2.close();
    return 0;
}

