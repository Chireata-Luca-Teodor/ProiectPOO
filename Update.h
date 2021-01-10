#include <iostream>
#include <string>
#include <fstream>
#include "Verificare.h"
using namespace std;
class Update
{
    string nume_tabel;
public:
    void update(string nume_tabel, string valoare1, string coloana1, string coloana2, string valoare2)
    {
        verificare v;
        int i = v.verif(nume_tabel);
        if (i)
        {
            //UPDATE nume_tabela SET nume_coloana = valoare WHERE nume_coloana = valoare
            ifstream file;
            file.open(nume_tabel + ".dat");
            ofstream file2;
            file2.open("copy");
            ifstream file3;
            ifstream file4;
            char x, y;
            string word, word2, word3, word5;
            int i = 0;
            while (!file.eof())
            {
                i = 0;
                file3.open(nume_tabel + ".txt");
                x = file.get();//scoatem cate o linie din fisierul dat
                while (x != '\n' && !file.eof())
                {
                    word3 += x;
                    x = file.get();
                }
                while (!file3.eof())
                {
                    x = file3.get();//parcurgem coloanele din txt
                    while (x != ' ' && !file3.eof())
                    {
                        word += x;
                        x = file3.get();
                    }
                    if (word != coloana2)//verificam daca am ajuns la coloana cautata
                    {
                        while (x != '\n' && !file3.eof())
                        {
                            x = file3.get();
                        }
                        while (word3[i] != ' ' && i < word3.length())
                        {
                            i++;
                        };
                        i++;
                    }
                    else
                    {
                        string word4;
                        while (word3[i] != ' ')//verificam daca valoarea = parametru
                        {
                            word4 += word3[i];
                            i++;
                        }
                        if (word4 == valoare2)
                        {
                            int j = 0;
                            file4.open(nume_tabel + ".txt");
                            while (j < word3.length())
                            {
                                while (!file4.eof())
                                {
                                    x = file4.get();//parcurgem coloanele din txt
                                    while (x != ' ' && !file4.eof())
                                    {
                                        word5 += x;
                                        x = file4.get();

                                    }
                                    while (x != '\n' && !file4.eof())
                                    {
                                        x = file4.get();
                                    }
                                    if (word5 == coloana1)
                                    {
                                        file2 << valoare1 << " ";
                                        while (word3[j] != ' ' && j < word3.length())
                                        {
                                            j++;
                                        }
                                        j++;
                                    }
                                    else
                                    {
                                        if (word3[j] != '\n')
                                        {
                                            string word6;
                                            while (word3[j] != ' ' && j < word3.length())
                                            {
                                                word6 += word3[j];
                                                j++;
                                            }
                                            file2 << word6 << " ";
                                            j++;
                                            word6.clear();
                                        }
                                    }
                                    word5.clear();


                                }
                                file2 << endl;
                            }
                            file4.close();
                        }
                        else
                        {
                            file2 << word3 << endl;
                        }
                    }
                    word.clear();

                }
                word3.clear();
                file3.close();
            }
            file.close();
            file2.close();
            nume_tabel += ".dat";
            char* table = nullptr;
            table = new char[nume_tabel.length() + 1];
            strcpy_s(table, nume_tabel.length() + 1, nume_tabel.c_str());
            remove(table);
            int result = rename("copy", table);
        }
        else
        {
            cout << "fisierul nu exista :(";
        }
    }

};
