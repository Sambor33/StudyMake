#include "MyClass.h"
#include "Exception.h"
int main ()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    int operation;
    do {
        wcout<<L"Введите операцию (0-Выход , 1- Зашифрование, 2 - Расшифрование): ";
        wcin>>operation;
        wstring text;
        if (operation == 1) {
            try {
                wstring key;
                wcout<<L"Введите ключ (количество столбцов) = ";
                wcin.ignore();
                getline(wcin,key);
                MarshCipher thiscipher(key);
                wcout<<L"Введите текст для зашифрования: ";
                getline(wcin,text);
                wstring result = thiscipher.Encryct(text);
                wcout<<L"Зашифрованный текст: \n"<<result<<endl;
            } catch (MyException&ex) {
                wcout<<ex.what()<<endl;
            }
        }
        if (operation == 2 ) {
            try {
                wstring key;
                wcout<<L"Введите ключ (количество столбцов) = ";
                wcin.ignore();
                getline(wcin,key);
                MarshCipher thiscipher(key);
                wcout<<L"Введите текст для расшифрования: ";
                getline (wcin,text);
                wstring result = thiscipher.Decryct(text);
                wcout<<L"Расшифрованный текст: \n"<<result<<endl;
            } catch (MyException&ex) {
                wcout<<ex.what()<<endl;
            }
        }
        if (operation!=1 and operation!=2 and operation!=0) {
            wcout<<L"Неизвестная операция, попробуйте еще раз"<<endl;;
        }
    } while(operation!=0);
    return 0;
}
