#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <locale>
using namespace std;
class MyException : public exception
{
private:
    wstring error;
    wstring descpription;
    bool static CheckAlpha (const wstring&text,const wstring&EnAlpha,const wstring&RusAlpha);
public:
    MyException (const wstring&err,const wstring&desc);
    wstring what () noexcept;
    bool static CheckKey (const wstring&key);
    bool static CheckText (const wstring&text,const int&key);
};
