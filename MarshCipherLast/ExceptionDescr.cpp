#include "Exception.h"
MyException::MyException (const wstring&err,const wstring&des)
{
    error = err;
    descpription = des;
}
void MyException::what () noexcept
{
    wcout<<L"Ошибка : "<<error<<L"Описание ошибки : "<<descpription<<endl;
}
bool MyException::CheckKey (const wstring&key)
{
    try {
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
            throw MyException(L"Некорректный ввод ключа. ",L"Ключ должен быть целым числом больше нуля");
        }
        return 1;
    } catch (MyException&ex) {
        ex.what();
    }
    exit (0);
}
bool MyException::CheckText (const wstring&text,const int&key)
{
    try {
        int len = text.size ();
        if (text.empty()) {
            throw MyException(L"Некорректный ввод текста. ",L"Пустой текст. ");
        }
        if (len<=key) {
            throw MyException(L"Некорректный ввод текcта. ",L"Количество символов в тексте должно быть больше размера ключа. ");
        }
        for (int i=0; i<len; i++) {
            if (!iswalpha(text[i])) {
                throw MyException(L"Некорректный ввод текста. ",L"Текст должен содержать буквы без пробелов и прочих символов.");
            }
        }
        return 1;
    } catch (MyException&ex) {
        ex.what();
    } catch (exception&ex) {
        wcout<<ex.what()<<endl;
    }
    exit(0);
}
