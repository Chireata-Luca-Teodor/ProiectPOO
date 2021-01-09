#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class verificare
{
public:
    int verif(string filename)
    {
        ifstream file;
        file.open("files.txt");
        string word;
        char x;
        int sw = 0;
        while (!file.eof() && sw != 1)
        {
            x = file.get();
            while (x != ' ' && !file.eof())
            {
                word = word + x;
                x = file.get();
                if (word == "\n")
                {
                    word.clear();
                }
            }
            if (filename == word)
            {
                sw = 1;
            }
            else
            {
                word.clear();
            }
        }
        file.close();
        return sw;

    }
    friend class CreateTable;
};
