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
public:
    void stergere(string nume_tabel)
    {
        char* table = nullptr;
        nume_tabel += ".txt";
        table = new char[nume_tabel.length() + 1];
        strcpy_s(table, nume_tabel.length() + 1, nume_tabel.c_str());
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
    string nume_tabel;
public:
    void insert(string nume_tabel)
    {
        string word;
        string name;
        char x;
        ofstream file;
        file.open(nume_tabel + ".dat", std::ios_base::app);
        ifstream tabel;
        tabel.open(nume_tabel + ".txt");
        while (!tabel.eof())
        {
            cout << "Inserati in " << nume_tabel + ".txt" << " ";
            x = tabel.get();

            while (x != ' ')
            {
                word = word + x;
                x = tabel.get();
            }
            cout << word << ", de tip ";
            word = "";
            x = tabel.get();
            while (x != ' ')
            {
                word = word + x;
                x = tabel.get();
            }
            cout << word << ", dimensiune ";
            word = "";
            x = tabel.get();

            while (x != ' ')
            {
                word = word + x;
                x = tabel.get();
            }
            cout << word << " si val implicita ";
            word = "";
            x = tabel.get();

            while (x != ' ')
            {
                word = word + x;
                x = tabel.get();
            }
            cout << word << endl;
            word = "";
            cin >> name;
            file << name << " ";
            x = tabel.get();
            word += x;
            if (word == "\n")
            {
                x = tabel.get();
                word = "";
            }
        }
        file << endl;
        file.close();
        tabel.close();
    }
};

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
    }
};

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

};

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
        //x = file.get();
        //while (x != ' ')
        //{
        //    word += x;
        //    x = file.get();
        //
        //}
        //tabel << word << " ";
        //word.clear();*/
        char y = '\n';
        string key2 = key;
        key = y + key;
        while (!file.eof())
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
                while (x != '\n' && !file.eof())
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
        }
        // /*while (getline(file,word))
        // {
        //     tabel << word << endl;
        // }*/
        file.close();
        tabel.close();
        nume_tabel += ".dat";
        char* table = nullptr;
        table = new char[nume_tabel.length() + 1];
        strcpy_s(table, nume_tabel.length() + 1, nume_tabel.c_str());
        remove(table);
        int result = rename("copy", table);
    }
};




int main()
{
    //CreateTable t;
    //t.citire();
    //DropTable d;
    //d.stergere("copie5");
    //DisplayTable d;
    //d.afisare("Studenti");
    //Insert i;
    //i.insert("Studenti");
    //Select s;
    //s.select("Studenti", "Cocolici");
    //Update u;
    //u.update("Studenti", "Luca");
    Delete d;
    d.deletee("studenti", "Cocolici");
}


