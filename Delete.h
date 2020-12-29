#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Delete
{
    string nume_tabel;
public:
    void deletee(string nume_tabel, string key)
    {
        ifstream file;
        file.open(nume_tabel + ".dat");
        ofstream tabel;
        tabel.open("copy");
        string word;
        char x;
        char y = '\n';
        string key2 = key;
        key = y + key;
        x = file.get();
        word += x;
        string copie;
        copie = "";
        copie += x;
        while (!file.eof() && copie != "")
        {
            x = file.get();
            while (x != ' ' && !file.eof())
            {
                word += x;
                x = file.get();
            }
            if (word == key || word == key2)
            {
                x = file.get();
                while (x != '\n')
                {
                    x = file.get();
                }
                tabel << endl;
            }
            else
            {
                tabel << word << " ";
            }

            word.clear();
            copie.clear();
            copie += x;
        }
        file.close();
        tabel.close();
        nume_tabel += ".dat";
        char* table = nullptr;
        table = new char[nume_tabel.length() + 1];
        strcpy_s(table, nume_tabel.length() + 1, nume_tabel.c_str());
        remove(table);
        int result = rename("copy", table);
    }
    friend class Inter;
};
