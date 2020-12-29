#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Update
{
    string nume_tabel;
public:
    void update(string nume_tabel, string key)
    {
        ifstream file;
        file.open(nume_tabel + ".dat");
        ofstream file2;
        file2.open("copy");
        ifstream file3;
        file3.open(nume_tabel + ".txt");
        string word, word3, atribut3;
        char x, y;
        char z = '\n';
        int is = 0;
        string keyz = key;
        key = z + key;
        while (!file.eof())
        {
            x = file.get();
            while (x != ' ' && !file.eof())
            {
                word += x;
                x = file.get();
            }
            if (word == key || word == keyz)
            {
                x = file.get();
                while (x != '\n')
                {
                    x = file.get();
                }
                file2 << endl;
                while (!file3.eof())
                {


                    y = file3.get();
                    while (y != ' ' && !file3.eof())
                    {
                        word3 += y;
                        y = file3.get();
                    }
                    if (!file3.eof())
                    {
                        cout << word3 << ": ";
                        cin >> atribut3;
                        file2 << atribut3 << " ";
                        word3.clear();
                        y = file3.get();
                        while (y != '\n')
                        {
                            y = file3.get();
                        }
                    }
                }
                file2 << endl;
            }
            else
            {
                file2 << word << " ";
            }
            word.clear();
        }
        file.close();
        file2.close();
        file3.close();
        nume_tabel += ".dat";
        char* table = nullptr;
        table = new char[nume_tabel.length() + 1];
        strcpy_s(table, nume_tabel.length() + 1, nume_tabel.c_str());
        remove(table);
        int result = rename("copy", table);
    }
    friend class Inter;

};
