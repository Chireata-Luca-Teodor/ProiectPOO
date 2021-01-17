#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class import
{
public:
    string tabel;
    string fisier;
    string separator;
    void imp()
    {
        ifstream file;
        file.open(fisier + ".csv");
        ofstream file2;
        file2.open(tabel + ".dat", std::ios_base::app);
        char x;
        string text;
        while (!file.eof())
        {
            x = file.get();
            text += x;


        }
        string text2;
        for (int i = 0; i < text.length() - 2; i++)
        {
            text2 += text[i];
        }
        file2 << text2 << endl;
        file2.close();
        file.close();
    }
};