/**
* @file Exception.h
* @author Самборский И.С.
* @version 1.0
* @brief Описание класса MyException
* @date 21.05.2021
* @copyright ИБСТ ПГУ
*/
#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <locale>
using namespace std;
///@brief Собственный класс исключений
class MyException : public exception
{
private:
    ///@brief поле ошибки, в котором указывается ее вид.
    wstring error;
    ///@brief поле ошибки, в котором указывается ее описание.
    wstring description;
public:
    /** 
    * @brief Конструктор инициализации ошибки строками.
    * @param err - вид ошибки.
    * @param desc - описание ошибки.
    * @details err присваивается приватному полю error,а desc присваивавется приватному полю description.
    **/
    MyException (const wstring&err,const wstring&desc);
    ///@brief Метод, возвращающий информацию об ошибке.
    wstring what () noexcept;
};
