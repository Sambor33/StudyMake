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
    wstring description;
public:
    MyException (const wstring&err,const wstring&desc);
    wstring what () noexcept;
};
