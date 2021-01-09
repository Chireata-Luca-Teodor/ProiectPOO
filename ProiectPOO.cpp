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
    Inter i;
    ifstream file;
    file.open("copie2.txt");
    string word;
    char x;
    int sw = 0;
    while (!file.eof())
    {
        x = file.get();
        while (x != '\n' && !file.eof())
        {
            word = word + x;
            x = file.get();
        }
        i.interp(word);
        word.clear();
    }
    file.close();
}


