#include <iostream>
#include <string>
#include <fstream>
using namespace std;
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
        if (remove(table) != 0)
            perror("Error deleting table");
        else
            puts("Table successfully deleted");
    }
    friend class inter;
};
