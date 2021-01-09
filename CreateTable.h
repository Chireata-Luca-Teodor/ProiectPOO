#include <iostream>
#include <string>
#include <fstream>
#include "Verificare.h"
using namespace std;
class CreateTable
{
private:
    string nume_tabel;
    int nr_coloane;
    string nume_coloana;
    string tip;
    int dimensiune;
    string valoare_implicita;
public:
    void citire(string nume_tabel, string text)
    {
        verificare v;
        if (!v.verif(nume_tabel))
        {
            ofstream f;
            f.open("files.txt", std::ios_base::app);
            f << nume_tabel << " " << endl;
            f.close();
            ofstream file;
            file.open(nume_tabel + ".txt");
            if (text[0] = '(')
            {
                for (int i = 1; i < text.length(); i++)
                {
                    if (text[i] != '(' && text[i] != ',' && text[i] != ')' && text[i] != ' ')
                    {
                        file << text[i];
                        cout << text[i];
                    }
                    else if (text[i] == ',')
                    {
                        file << " ";
                        cout << " ";
                    }
                    else if (text[i] == ')')
                    {
                        file << " ";
                        file << endl;
                        cout << endl;
                    }

                }
            }
            file.close();
        }
        else
        {
            cout << "fisierul deja exista!";
        }
    }
    friend class inter;
    friend class verificare;
};