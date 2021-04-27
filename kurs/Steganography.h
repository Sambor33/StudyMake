#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Steganography
{
private:
    int degree;
    unsigned char tmask ();
    unsigned char imask ();
public:
    Steganography (const int&key);
    int Concealment (const string&bmp_path,const string&hidden_path);
    int Extraction (const string&bmp_path,const string&hidden_path,const int&hiddensize);
};
