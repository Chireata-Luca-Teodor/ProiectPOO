#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class DisplayTable
{
    string nume_tabel;
public:
    void afisare(string nume_tabel)
    {
        ifstream file;
        string space = " ";
        char x;
        string word;
        file.open(nume_tabel + ".txt");
        char s;
        x = file.get();

        while (x != ' ')
        {
            word = word + x;
            x = file.get();
        }
        cout << word << "     |";
        word.clear();
        while (!file.eof())
        {
            x = file.get();
            if (x == '\n')
            {
                x = file.get();
                while (x != ' ' && !file.eof())
                {
                    word = word + x;
                    x = file.get();
                }
                cout << word << "     |";
                word.clear();
            }

        }
        file.close();

    }
    friend class inter;
};
