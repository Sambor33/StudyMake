#include "modAlphaCipher.h"
#include "Exception.h"
using namespace std;
int main()
{
    locale loc("ru_RU.UTF-8");
    locale::global(loc);
    wstring key;
    wstring text;
    unsigned op;
    do {
        wcout<<L"Введите операцию (0-выход, 1-зашифрование, 2-расшифрование): ";
        wcin>>op;
        if (op==1) {
            try {
                wcout<<L"Введите ключ: ";
                wcin.ignore();
                getline(wcin,key);
                modAlphaCipher cipher(key);
                wcout<<L"Введите текст: ";
                getline(wcin,text);
                wstring res = cipher.encrypt(text);
                wcout<<L"Зашифрованный текст: "<<res<<endl;
            } catch (MyException&ex) {
                wcout<<ex.what()<<endl;
            }
        }
        if (op==2) {
            try {
                wcout<<L"Введите ключ: ";
                wcin.ignore();
                getline(wcin,key);
                modAlphaCipher cipher(key);
                wcout<<L"Введите текст: ";
                getline(wcin,text);
                wstring res = cipher.decrypt(text);
                wcout<<L"Расшифрованный текст: "<<res<<endl;
            } catch (MyException&ex) {
                wcout<<ex.what()<<endl;
            }
        }
        if (op > 2) {
            wcout<<L"Некорректная операция"<<endl;
        }
    } while (op!=0);
    return 0;
}
