#include <Steganography.h>
int main()
{
    int operation;
    int key;
    do {
        cout<<"Введите операцию : 1 - Зашифрование , 2 - Расшифрование , 0 - Выход = ";
        cin>>operation;
        if (operation==1) {
            cout<<"Введите степень кодирования (1/2/4/8) = ";
            cin>>key;
            if (key !=1 and key !=2 and key !=4 and key !=8) {
                cout<<"Ошибка ввода, попробуйте еще раз"<<endl;
                continue;
            }
            string bmp_path,hidden_path;
            cout<<"Введите путь к bmp-контейнеру : ";
            cin>>bmp_path;
            cout<<"Введите путь к файлу, данные из которого будут зашифровываться : ";
            cin>>hidden_path;
            Steganography thisoperation(key);
            thisoperation.Concealment (bmp_path,hidden_path);
        }
        if (operation==2) {
            cout<<"Введите степень кодирования (1/2/4/8) = ";
            cin>>key;
            if (key !=1 and key !=2 and key !=4 and key !=8) {
                cout<<"Ошибка ввода, попробуйте еще раз"<<endl;
                continue;
            }
            int hiddensize;
            string bmp_path,hidden_path;
            cout<<"Введите путь к bmp-контейнеру с зашифрованными данными : ";
            cin>>bmp_path;
            cout<<"Введите путь к файлу, в который будут записаны зашифрованные в контейнере данные : ";
            cin>>hidden_path;
            cout<<"Введите длину зашифрованного в контейнере файла (в байтах) : ";
            cin>>hiddensize;
            Steganography thisoperation(key);
            thisoperation.Extraction(bmp_path,hidden_path,hiddensize);
        }
    } while (operation!=0);
}
