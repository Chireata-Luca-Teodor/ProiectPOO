#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CreateTable
{
private :
    string nume_tabel;
    int nr_coloane;
    string nume_coloana;
    string tip;
    int dimensiune;
    string valoare_implicita;
public :
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
};

class DropTable
{   
    string nume_tabel;
    //string file = nume_tabel + ".txt";
public:
    void stergere(string nume_tabel)
    {
        char* table = nullptr;
        nume_tabel += ".txt";
        table = new char[nume_tabel.length() + 1];
        strcpy_s(table, nume_tabel.length() + 1, nume_tabel.c_str());
        //string txt = ".txt";
        //ofstream file;
        ////file.open(nume_tabel + txt);
        //file.open(nume_tabel + txt, std::ofstream::out | std::ofstream::trunc);
        //file.close();
        //remove(nume_tabel + ".txt");
        if (remove(table) != 0)
            perror("Error deleting file");
        else
            puts("File successfully deleted");
    }
};

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
            //file >> s;
            //cout << s << "     |";
            x = file.get();
            if (x == '\n')
            {
                x = file.get();
                while (x != ' ')
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

};

class Insert
{

};

class Select
{

};

class Update
{

};

class Delete
{
    
};




int main()
{
    //CreateTable t;
    //t.citire();
    //DropTable d;
    //d.stergere("asd");
    DisplayTable d;
    d.afisare("Studenti");
}


