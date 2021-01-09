#include <iostream>
#include <string>
#include <fstream>
#include "Verificare.h"
using namespace std;
class Insert
{
    string nume_tabel;
public:
    void insert(string nume_tabel, string text)
    {
        verificare v;
        int i = v.verif(nume_tabel);
        if (i)
        {
            string word;
            string name;
            char x;
            ofstream file;
            file.open(nume_tabel + ".dat", std::ios_base::app);
            ifstream tabel;
            tabel.open(nume_tabel + ".txt");
            int i = 1;
            string copie;
            while (i < text.length())
            {

                while (text[i] != ',' && i < text.length())
                {
                    copie += text[i];
                    i++;
                }
                file << copie << " ";
                copie = "";
                i++;
            }
            file << endl;
            file.close();
            tabel.close();
        }
        else
        {
            cout << "fisierul nu exista :(";
        }
    }
};
