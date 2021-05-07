#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <locale>
#include <vector>
using namespace std;
class MyException : public exception
{
private:
    wstring error;
    wstring descpription;
public:
    MyException (const wstring&err,const wstring&desc);
    void what () noexcept;
    bool static CheckKey (const wstring&key);
    bool static CheckText (const wstring&text,const int&key);
};
