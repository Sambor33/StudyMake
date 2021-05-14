#include "modAlphaCipher.h"
#include "Exception.h"
modAlphaCipher::modAlphaCipher(const wstring& skey)
{
    for (unsigned i=0; i<numAlpha.size(); i++) {
        alphaNum[numAlpha[i]]=i;
    }
    key = convert(GetValidKey(skey));
}
wstring modAlphaCipher::GetValidKey (const wstring& key)
{
    wstring wkey = key;
    if (key.empty()) {
        throw MyException (L"Некорректный ввод ключа. ",L"Пустой ключ. ");
    }
    int len = wkey.size();
    for (int i=0; i<len; i++) {
        if (iswlower(wkey[i])) {
            wkey[i] = towupper (wkey[i]);
        }
        if (numAlpha.find(wkey[i])==string::npos) {
            throw MyException (L"Некорректный ввод ключа. ",L"Ключ содержит недопустимые символы.");
        }
    }
    return wkey;
}
wstring modAlphaCipher::GetValidText (const wstring& text)
{
    wstring wtext = text;
    if(wtext.empty ()) {
        throw MyException (L"Некорректный ввод текста. ",L"Пустой текст. ");
    }
    int len = wtext.size ();
    for (int i=0; i<len; i++) {
        if (iswlower(wtext[i])) {
            wtext[i] = towupper (wtext[i]);
        }
        if (numAlpha.find(wtext[i])==string::npos) {
            throw MyException (L"Некорректный ввод текста. ",L"Текст содержит недопустимые символы. ");
        }
    }
    return wtext;
}
wstring modAlphaCipher::encrypt(const wstring& open_text)
{
    vector<int> work = convert(GetValidText(open_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
wstring modAlphaCipher::decrypt(const wstring& cipher_text)
{
    vector<int> work = convert(GetValidText(cipher_text));
    for(unsigned i=0; i < work.size(); i++) {
        work[i] = (work[i] + alphaNum.size() - key[i % key.size()]) % alphaNum.size();
    }
    return convert(work);
}
inline vector<int> modAlphaCipher::convert(const wstring& s)
{
    vector<int> result;
    for(auto c:s) {
        result.push_back(alphaNum[c]);
    }
    return result;
}
inline wstring modAlphaCipher::convert(const vector<int>& v)
{
    wstring result;
    for(auto i:v) {
        result.push_back(numAlpha[i]);
    }
    return result;
}
