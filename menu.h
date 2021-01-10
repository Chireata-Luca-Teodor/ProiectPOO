#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Inter.h"

using namespace std;
class menu
{
public:
    void meniu()
    {
        Inter i;
        string text;
        char input[100];
        cout << "Alegeti o optiune" << endl;
        cout << "1.Vrei sa introduci comenzile din consola?" << endl << "2.Ai deja comenzile pregatite in fisiere?" << endl;
        cout << "Optiune: ";
        int a;
        cin >> a;
        cout << endl;
        ifstream file;
        string word;
        char x;
        int sw = 0;
        int j = 15;
        string copie;
        switch (a)
        {
        case 1:
            cin.getline(input, sizeof(input));
            cin.getline(input, sizeof(input));
            text += input;
            i.interp(text);
            break;
        case 2:
            cout << "Introdu ceva de genul: proiectPOO.exe comenzi.txt [comenzi2.txt];" << endl;
            cin.getline(input, sizeof(input));
            cin.getline(input, sizeof(input));
            text += input;
            while (j < text.length())
            {
                if (text[j] == ' ')
                {
                    j++;
                    copie.clear();
                }
                while (text[j] != ' ' && j < text.length())
                {
                    copie += text[j];
                    j++;
                }
                file.open(copie);
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
            break;
        }
    }
};