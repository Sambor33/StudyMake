#include "MyClass.h"
#include "Exception.h"
MarshCipher::MarshCipher (const wstring &wkey)
{
    MyException::CheckKey(wkey);
    key=stoi(wkey);
}
int MarshCipher::StrNum (const wstring &text)
{
    double dkey=key,dsize=text.size(),dstr;
    dstr=ceil(dsize/dkey);
    int str = dstr;
    return str;
}
int MarshCipher::SpaceNum(const wstring&text)
{
    int ost = text.size()%key;
    int spacenum = key-ost;
    if (spacenum == key) {
        spacenum = 0;
    }
    return spacenum;
}
wstring MarshCipher::Encryct(const wstring&text)
{
    MyException::CheckText(text,key);
    wstring newtext = text;
    int str = StrNum(text);
    wchar_t **arr= new wchar_t*[str];
    for (int k=0; k<str; k++) {
        arr[k]=new wchar_t[key];
    }
    int t=0;
    int size = text.size();
    for (int i=0; i<str; i++) {
        for (int k=0; k<key; k++,t++) {
            if (i*key+k<size+1) {
                arr[i][k] = text [t];
            } else {
                arr[i][k] = '\0';
            }
        }
    }
    int l=0;
    for (int k=key-1; k>-1; k--) {
        for (int i=0; i<str; i++,l++) {
            if (arr[i][k]!='\0') {
                newtext[l]=arr[i][k];
            } else {
                break;
            }
        }
    }
    for (int k=0; k<str; k++) {
        delete [] arr[k];
    }
    delete [] arr;
    return newtext;
}
wstring MarshCipher::Decryct(const wstring&text)
{
    wstring newtext = text;
    int str=StrNum(text);
    SpaceNum(text);
    int spacenum = SpaceNum(text);
    wchar_t **arr= new wchar_t*[str];
    for (int k =0; k<str; k++) {
        arr[k]=new wchar_t[key];
    }
    int l=0;
    for (int k=key-1; k>-1; k--) {
        if (spacenum == 0) {
            for (int i=0; i<str; i++,l++) {
                arr[i][k]=text[l];
            }
        } else {
            for (int i=0; i<str-1; i++,l++) {
                arr[i][k]=text[l];
                arr[str-1][k] = '\0';
            }
            spacenum--;
        }
    }
    int t=0;
    for (int i=0; i<str; i++) {
        for (int k=0; k<key; k++,t++) {
            if (arr[i][k]!='\0') {
                newtext[t] = arr[i][k];
            } else {
                break;
            }
        }
    }
    for (int k=0; k<str; k++) {
        delete [] arr[k];
    }
    delete [] arr;
    return newtext;
}

