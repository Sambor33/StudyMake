#pragma once
#include <string>
#include <cstring>
#include <iostream>
#include <locale>
#include <cmath>
#include <exception>
#include <cctype>
#include <vector>
using namespace std;
class MarshCipher
{
private:
    int key;
    int StrNum(const wstring &text);
    int SpaceNum(const wstring&text);
    int TextCheck (const wstring&text);
public:
    MarshCipher(const wstring &key);
    wstring Encryct(const wstring&text);
    wstring Decryct(const wstring&text);
};

