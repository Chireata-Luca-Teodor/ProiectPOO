#include <iostream>
#include <string>
#include <fstream>
using namespace std;
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
                while (x != ' ' && !file.eof())
                {
                    word = word + x;
                    x = file.get();
                }
                if (word != "")
                {
                    cout << word << "     |";
                    word.clear();
                }

            }

        }
        cout << endl;
        file.close();
        ifstream data;
        data.open(nume_tabel + ".dat");
        x = data.get();

        while (x != ' ')
        {
            word = word + x;
            x = data.get();
        }
        cout << word << " "; /*<< "     |";*/
        word.clear();
        while (!data.eof())
        {
            //file >> s;
            //cout << s << "     |";
            x = data.get();
            while (x != ' ' && !data.eof())
            {
                word = word + x;
                x = data.get();
            }
            if (word != "")
            {
                cout << word << " ";
                word.clear();
            }
            if (x == '\n')
            {
                cout << endl;
            }

        }
        data.close();
        cout << endl;
    }
    friend class inter;
};