#include "Exception.h"
MyException::MyException (const wstring&err,const wstring&desc) 
{
    error = err;
    description = desc;
}
wstring MyException::what () noexcept
{
    return L"Ошибка: "+error+L"Описание: "+description;
}
