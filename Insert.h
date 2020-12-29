#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Insert
{
    string nume_tabel;
public:
    void insert(string nume_tabel, string text)
    {
        string word;
        string name;
        char x;
        ofstream file;
        file.open(nume_tabel + ".dat", std::ios_base::app);
        ifstream tabel;
        tabel.open(nume_tabel + ".txt");
        int i = 0;
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
    friend class inter;
};
