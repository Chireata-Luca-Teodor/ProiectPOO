#include <iostream>
#include <string>
#include <fstream>
using namespace std;
class Inter
{
    string input;
public:
    //CREATE TABLE nume_tabel ((nume_coloana_1, tip, dimensiune, val_implicita).....(..))
    //DROP TABLE nume_tabel
    //DISPLAY TABLE table_name
    //INSERT INTO nume_tabela (x,y,z...)
    //DELETE FROM nume_tabela WHERE nume_coloana = valoare
    //SELECT (...) FROM nume_tabela
    //UPDATE nume_tabela SET nume_coloana = valoare WHERE nume_coloana = valoare
    void interp(string input)
    {
        string test = "";
        char x;
        int i = 0;
        test += input[i];
        i++;
        while (input[i] != ' ' && i < input.length())
        {
            test += input[i];
            i++;
        }
        if (test == "CREATE")
        {
            test += input[i];
            i++;
            while (input[i] != ' ')
            {
                test += input[i];
                i++;
            }
            if (test == "CREATE TABLE")
            {
                test.clear();
                i++;
                while (input[i] != ' ')
                {
                    test += input[i];
                    i++;
                }
                i++;
                string text;
                for (int j = i; j < input.length(); j++)
                {
                    text += input[j];
                }
                CreateTable c;
                c.citire(test, text);
            }
        }
        else
            if (test == "DROP")
            {
                test += input[i];
                i++;
                while (input[i] != ' ')
                {
                    test += input[i];
                    i++;
                }
                if (test == "DROP TABLE")
                {
                    i++;
                    test = "";
                    test += input[i];
                    i++;
                    while (input[i] != ' ' && i < input.length())
                    {
                        test += input[i];
                        i++;
                    }
                    DropTable d;
                    d.stergere(test);
                }
            }
            else if (test == "DISPLAY")
            {
                test += input[i];
                i++;
                while (input[i] != ' ')
                {
                    test += input[i];
                    i++;
                }
                if (test == "DISPLAY TABLE")
                {
                    i++;
                    test = "";
                    test += input[i];
                    i++;
                    while (input[i] != ' ' && i < input.length())
                    {
                        test += input[i];
                        i++;
                    }
                    DisplayTable d;
                    d.afisare(test);
                }
            }
            else if (test == "INSERT")
            {
                test += input[i];
                i++;
                while (input[i] != ' ')
                {
                    test += input[i];
                    i++;
                }
                if (test == "INSERT INTO")
                {
                    i++;
                    test = "";
                    test += input[i];
                    i++;
                    while (input[i] != ' ' && i < input.length())
                    {
                        test += input[i];
                        i++;
                    }
                    string asd;
                    while (i < input.length())
                    {
                        asd += input[i];
                        i++;
                    }
                    Insert i;
                    i.insert(test, asd);
                }
            }
            else if (test == "DELETE")
            {
                test += input[i];
                i++;
                while (input[i] != ' ')
                {
                    test += input[i];
                    i++;
                }
                if (test == "DELETE FROM")
                {
                    i++;
                    test = "";
                    test += input[i];
                    i++;
                    while (input[i] != ' ' && i < input.length())
                    {
                        test += input[i];
                        i++;
                    }
                    string table = test;
                    i++;
                    test = "";
                    test += input[i];
                    i++;
                    while (input[i] != ' ' && i < input.length())
                    {
                        test += input[i];
                        i++;
                    }
                    if (test == "WHERE")
                    {
                        while (input[i] != '=' && i < input.length())
                        {
                            i++;
                        }
                        i++; i++;
                        string value = "";
                        while (i < input.length())
                        {
                            value += input[i];
                            i++;
                        }
                        Delete d;
                        d.deletee(table, value);
                    }
                }
            }
            else
                if (test == "SELECT")
                {
                    i++;
                    test = "";
                    test += input[i];
                    i++;
                    while (input[i] != ' ' && i < input.length())
                    {
                        test += input[i];
                        i++;
                    }
                    string key = test;
                    i++;
                    test = "";
                    test += input[i];
                    i++;
                    while (input[i] != ' ' && i < input.length())
                    {
                        test += input[i];
                        i++;
                    }
                    if (test == "FROM")
                    {
                        i++;
                        test = "";
                        test += input[i];
                        i++;
                        while (input[i] != ' ' && i < input.length())
                        {
                            test += input[i];
                            i++;
                        }
                        Select s;
                        s.select(test, key);
                    }
                }
                else if (test == "UPDATE")
                {
                    //UPDATE nume_tabela SET nume_coloana = valoare WHERE nume_coloana = valoare
                    i++;
                    test = "";
                    test += input[i];
                    i++;
                    while (input[i] != ' ' && i < input.length())
                    {
                        test += input[i];
                        i++;
                    }
                    string table = test;
                    string valoare1, valoare2, coloana1, coloana2;
                    i++;
                    test = "";
                    test += input[i];
                    i++;
                    while (input[i] != ' ' && i < input.length())
                    {
                        test += input[i];
                        i++;
                    }
                    if (test == "SET")
                    {
                        i++;
                        while (input[i] != ' ')
                        {
                            coloana1 += input[i];
                            i++;
                        }
                        i += 3;
                        while (input[i] != ' ')
                        {
                            valoare1 += input[i];
                            i++;
                        }
                        i += 7;
                        while (input[i] != ' ')
                        {
                            coloana2 += input[i];
                            i++;
                        }
                        i += 3;
                        while (input[i] != ' ' && i < input.length())
                        {
                            valoare2 += input[i];
                            i++;
                        }
                        Update u;
                        u.update(table, valoare1, coloana1, coloana2, valoare2);
                    }

                }
                else {
                    cout << "Comanda este gresita!" << endl;
                }
    }
};