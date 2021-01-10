#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Select
{
    string nume_tabel;
public:
    void select(string nume_tabel, string key)
    {
        ifstream file;
        file.open(nume_tabel + ".dat");
        string word;
        char x;
        x = file.get();
        while (x != ' ')
        {
            word = word + x;
            x = file.get();
        }
        int is = 0;
        if (word == key)
        {
            cout << word << " ";
            is = 1;
        }
        word.clear();
        while (!file.eof() && is == 0)
        {
            x = file.get();
            while (x != ' ')
            {
                if (word + x != "\n")
                {
                    word = word + x;
                    //x = file.get();
                }
                x = file.get();
            }
            if (word == key)
            {
                cout << word << " ";
                is = 1;
            }
            word.clear();
        }
        string word2;
        if (is == 1)
        {
            while (word2 != "\n")
            {
                x = file.get();
                while (x != ' ')
                {
                    word = word + x;
                    x = file.get();
                }
                cout << word << " ";
                word.clear();
                x = file.get();
                word2 += x;
                word += x;
            }
        }
        file.close();
    }
};
