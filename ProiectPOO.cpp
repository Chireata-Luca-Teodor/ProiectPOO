#include <iostream>
#include <string>
#include <fstream>
#include "CreateTable.h"
#include "Display.h"
#include "DropTable.h"
#include "Insert.h"
#include "Select.h"
#include "Update.h"
#include "Delete.h"
#include "Inter.h"
using namespace std;

int main()
{
    cout << "Lista de comenzi:" << endl << endl;
    cout << "CREATE TABLE nume_tabel ((nume_coloana_1, tip, dimensiune, val_implicita).....(..))" << endl;
    cout << "DROP TABLE nume_tabel" << endl;
    cout << "DISPLAY TABLE table_name" << endl;
    cout << "INSERT INTO nume_tabela (x,y,z...)" << endl;
    cout << "DELETE FROM nume_tabela WHERE nume_coloana = valoare" << endl;
    cout << "SELECT (...) FROM nume_tabela" << endl;
    cout << "UPDATE nume_tabela SET nume_coloana = valoare WHERE nume_coloana = valoare" << endl << endl;
    cout << "Introduceti comanda :"<< endl;
    Inter i;
    string text;
    char input[100];
    cin.getline(input, sizeof(input));
    text += input;
    i.interp(text);   
}


