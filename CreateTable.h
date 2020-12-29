#include <iostream>
#include <string>
#include <fstream>
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
    //CREATE TABLE nume_tabel (nume_coloana1, tip, dimensiune, val_implicita) (..)...
    void citire()
    {
        cout << "Nume Tabel : ";
        cin >> nume_tabel;
        cout << endl;
        cout << "Numar coloane : ";
        cin >> nr_coloane;
        cout << endl;
        string txt = ".txt";
        if (nr_coloane > 0)
        {
            ofstream file;
            file.open(nume_tabel + txt);
            string buffer;
            for (int i = 0; i < nr_coloane; i++)
            {
                cout << "Nume Coloana " << i << " :";
                cin >> nume_coloana;
                file << nume_coloana << ' ';
                getline(cin, buffer);
                cout << endl;
                cout << "Tip: ";
                cin >> tip;
                file << tip << ' ';
                getline(cin, buffer);
                cout << endl;
                cout << "Dimensiune: ";
                cin >> dimensiune;
                file << dimensiune << ' ';
                getline(cin, buffer);
                cout << endl;
                cout << "Valoare implicita: ";
                cin >> valoare_implicita;
                file << valoare_implicita << ' ';
                getline(cin, buffer);
                cout << endl;
                file << endl;
            }
            file.close();
        }
    }
    friend class inter;
};