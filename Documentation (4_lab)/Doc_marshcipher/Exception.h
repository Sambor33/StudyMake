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
    wstring descpription;
    /**
     * @brief Функция определения алфавита текста.
     * @param text - текст, введенный пользователем для выполнения операций зашифрования/расшифрования.
     * @param EnAlpha - английский алфавит в виде строки.
     * @param RusAlpha - русский алфавит в виде строки.
     * @details Функция проверяет только первый элемент текста и выбрасывает исключение если он не является
     * символом ни русского, ни английского алфавита. Это приватный метод, использующийся в методе CheckText.
     * @return 1 - если, первый символ текста принадлежит к английскому алфавиту. 0 - если к русскому.
     **/
    bool static CheckAlpha (const wstring&text,const wstring&EnAlpha,const wstring&RusAlpha);
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
    /**
     * @brief Метод проверки ключа.
     * @param key - ключ, введенный пользователем.
     * @details Бросает исключение в случае если: ключ пустой, ключ содержит символы,отличные от цифр, ключ равен 0.
     **/
    bool static CheckKey (const wstring&key);
    /**
     * @brief Метод проверки текста.
     * @param text - текст, введенный пользователем для выполнения операций зашифрования/расшифрования.
     * @param key - ключ, обработанный программой.
     * @details Бросает исключение в случае если: текст пустой, текст содержит символы, не принадлежащие к русскому или
     * английскому алфавиту, текст содержит одновременно символы русского и английского алфавитов, длина текста меньше величины ключа.
     **/
    bool static CheckText (const wstring&text,const int&key);
};
