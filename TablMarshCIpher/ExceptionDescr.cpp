#include "Exception.h"
MyException::MyException (const wstring&err,const wstring&des)
{
    error = err;
    descpription = des;
}
wstring MyException::what () noexcept 
{
    return L"Ошибка : "+error+L"Описание ошибки : "+descpription;
}
bool MyException::CheckAlpha (const wstring&text,const wstring&EnAlpha,const wstring&RusAlpha)
{
    int first= 0;
    if (EnAlpha.find(text[first])==string::npos and RusAlpha.find(text[first])==string::npos) {
        throw MyException(L"Некорректный ввод текста. ",L"Текст должен состоять из букв английского или русского алфавита. ");
    }
    if (EnAlpha.find(text[first])!=string::npos) {
        return 1;
    }
    if (RusAlpha.find(text[first])!=string::npos) {
        return 0;
    }
}
bool MyException::CheckKey (const wstring&key)
{
    int len = key.size();
    if (key.empty()) {
        throw MyException(L"Некорректный ввод ключа. ",L"Пустой ключ. ");
    }
    for (int i=0; i<len; i++) {
        if (!isdigit(key[i])) {
            throw MyException(L"Некорректный ввод ключа. ",L"Ключ содержит недопустимые символы");
        }
    }
    int digitkey = stoi(key);
    if (digitkey<1) {
        throw MyException(L"Некорректный ввод ключа. ",L"Ключ должен быть целым числом больше единицы");
    }
    return 1;
}
bool MyException::CheckText (const wstring&text,const int&key)
{
    wstring const EnAlpha = L"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    wstring const RusAlpha = L"абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    int len = text.size ();
    if (text.empty()) {
        throw MyException(L"Некорректный ввод текста. ",L"Пустой текст. ");
    }
    if (CheckAlpha (text,EnAlpha,RusAlpha)) {
        for (int i=1; i<len; i++) {
            if (EnAlpha.find(text[i])==string::npos) {
                throw MyException(L"Некорректный ввод текста. ",L"Текст содержит буквы разных алфавитов или недопустимые символы");
            }
        }
    }
    if (!CheckAlpha(text,EnAlpha,RusAlpha)) {
        for (int i=1; i<len; i++) {
            if (RusAlpha.find(text[i])==string::npos) {
                throw MyException(L"Некорректный ввод текста. ",L"Текст содержит буквы разных алфавитов или недопустимые символы");
            }
        }
    }
    if (len<key) {
        throw MyException(L"Некорректный ввод текста.",L"Длина текста не может быть меньше величины ключа");
    }
    return 1;
}
