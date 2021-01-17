#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Inter.h"
#include "STL.h"

using namespace std;
class menu
{
public:
    void meniu()
    {
        Inter i;
        string text, text2;
        char input[100];
        cout << "Introdu ceva de genul: proiectPOO.exe comenzi.txt [comenzi2.txt];" << endl;
        cin.getline(input, sizeof(input));
        text2 += input;
        cout << endl;
        ifstream file;
        string word;
        char x;
        int sw = 0;
        int j = 15;
        string copie;
        if (text2 == "proiectPOO.exe")
        {
            cin.getline(input, sizeof(input));
            text += input;
            i.interp(text);
        }
        else if (text2 == "meniu")
        {
            cout << endl;
            cout << "1.vector" << endl << "2.set" << endl << "3.list" << endl << "4.map" << endl;
            int a;
            string file;
            cin >> a;
            stl b;
            cout << "File: ";
            cin >> file;
            cout << endl;
            b.file2 = file;
            switch (a)
            {
            case 1:
                b.vec();
                break;
            case 2:
                b.set1();
                break;
            case 3:
                b.lis();
                break;
            case 4:
                b.map1();
                break;
            }
        }
        else
        {
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
        }
    }
};