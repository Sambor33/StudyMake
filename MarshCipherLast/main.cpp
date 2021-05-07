#include "MyClass.h"
#include "Exception.h"
int main ()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring coutkey;
    int operation;
    wcout<<L"Введите ключ (количество столбцов) = ";
    getline(wcin,coutkey);
    MarshCipher thiscipher(coutkey);
    do {
        wcout<<L"Введите операцию (0-Выход , 1- Зашифрование, 2 - Расшифрование): ";
        wcin>>operation;
        wstring text;
        if (operation == 1) {
            wcout<<L"Введите текст для зашифрования: ";
            wcin.ignore();
            getline(wcin,text);
            wcout<<L"Зашифрованный текст: \n"<<thiscipher.Encryct(text)<<endl;
        }
        if (operation == 2 ) {
            wcout<<L"Введите текст для расшифрования: ";
            wcin.ignore();
            getline (wcin,text);
            wcout<<L"Расшифрованный текст: \n"<<thiscipher.Decryct(text)<<endl;
        }
        if (operation!=1 and operation!=2 and operation!=0) {
            wcout<<L"Неизвестная операция, попробуйте еще раз"<<endl;;
        }
    } while(operation!=0);
    return 0;
}
