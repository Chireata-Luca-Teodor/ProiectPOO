#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <list>
#include <map>
using namespace std;
class stl
{
public:
    string file2;
    void vec()
    {
        vector<string> v;
        ifstream file;
        file.open(file2 + ".dat");
        string text;
        char x;
        while (!file.eof())
        {
            x = file.get();
            while (x != '\n' && !file.eof())
            {
                text += x;
                x = file.get();
            }
            v.push_back(text);
            text.clear();
        }
        file.close();
        for (auto i = v.begin(); i != v.end(); ++i)
            cout << *i << " ";
    }
    void set1()
    {
        set<string, greater<string> > s1;
        ifstream file;
        file.open(file2 + ".dat");
        string text;
        char x;
        while (!file.eof())
        {
            x = file.get();
            while (x != '\n' && !file.eof())
            {
                text += x;
                x = file.get();
            }
            s1.insert(text);
            text.clear();
        }
        file.close();
        for (auto i = s1.begin(); i != s1.end(); ++i)
            cout << *i << " ";
    }
    void lis()
    {
        list <string> l;
        ifstream file;
        file.open(file2 + ".dat");
        string text;
        char x;
        while (!file.eof())
        {
            x = file.get();
            while (x != '\n' && !file.eof())
            {
                text += x;
                x = file.get();
            }
            l.push_back(text);
            text.clear();
        }
        file.close();
        for (auto i = l.begin(); i != l.end(); ++i)
            cout << *i << " ";
    }
    void map1()
    {
        map<string, string> m;
        ifstream file;
        file.open(file2 + ".dat");
        string text, copy;
        char x;
        while (!file.eof())
        {
            x = file.get();
            while (x != '\n' && !file.eof())
            {
                text += x;
                x = file.get();
                if (x == ' ')
                {
                    x = file.get();
                    copy = text;
                    text.clear();
                }
            }
            m.insert(pair<string, string>(copy, text));
            text.clear();
            copy.clear();
        }
        file.close();
        map<string, string>::iterator itr;
        for (itr = m.begin(); itr != m.end(); ++itr)
            cout << itr->first << "~" << itr->second << endl;
    }
};