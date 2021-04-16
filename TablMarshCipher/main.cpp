#include "MyClass.h"
int main ()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int coutkey;
    int operation;
    wcout<<L"Введите ключ (количество столбцов) = ";
    wcin>>coutkey;
    if (coutkey<1 or coutkey>10000) {
        wcout<<L"Ошибка ввода ключа"<<endl;
        return 1;
    }
    MarshCipher thiscipher(coutkey);
    do {
        wcout<<L"Введите операцию (0-Выход , 1- Зашифрование, 2 - Расшифрование): ";
        wcin>>operation;
        wstring text;
        if (operation == 1) {
            wcout<<L"Введите текст для зашифрования: ";
            wcin>>text;
            if (thiscipher.Encryct(text)==text) {
                return 1;
            } else {
                wcout<<L"Зашифрованный текст: \n"<<thiscipher.Encryct(text)<<endl;
            }
        }
        if (operation == 2 ) {
            wcout<<L"Введите текст для расшифрования: ";
            wcin>>text;
            if (thiscipher.Decryct(text)==text) {
                return 1;
            } else {
                wcout<<L"Расшифрованный текст: \n"<<thiscipher.Decryct(text)<<endl;
            }
        }
        if (operation!=1 and operation!=2 and operation!=0) {
            wcout<<L"Неизвестная операция, попробуйте еще раз"<<endl;;
        }
    } while(operation!=0);
    return 0;
}
