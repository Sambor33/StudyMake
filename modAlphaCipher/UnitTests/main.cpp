#include <UnitTest++/UnitTest++.h>
#include "Exception.h"
#include "modAlphaCipher.h"
SUITE (KeyTest)
{
    TEST(UpCaseRussianKey) {
        setlocale (LC_ALL,"ru_RU.UTF-8");
        modAlphaCipher (L"РУССКИЙАЛФАВИТ");
        CHECK (true);
    }
    TEST(LowCaseRussianKey) {
        modAlphaCipher (L"русскийалфавит");
        CHECK (true);
    }
    TEST (MixedCaseRussianKey) {
        modAlphaCipher (L"РусскийАлфавит");
        CHECK (true);
    }
    TEST (EmptyKey) {
        CHECK_THROW (modAlphaCipher (L""),MyException);
    }
    TEST (DigitsInKey) {
        CHECK_THROW (modAlphaCipher (L"Циф9ра"),MyException);
    }
    TEST (PunctCharInKey) {
        CHECK_THROW (modAlphaCipher (L"Знак!"),MyException);
    }
    TEST (EnglishKey) {
        CHECK_THROW (modAlphaCipher (L"EnglishLanguage"),MyException);
    }
    TEST (SpaceInKey) {
        CHECK_THROW (modAlphaCipher (L"Пробел обнаружен"),MyException);
    }
}
struct Key {
    modAlphaCipher *k;
    Key ()
    {
        k = new modAlphaCipher (L"КЛЮЧ");
    }
    ~Key ()
    {
        delete k;
    }
};
SUITE (EncodeTest)
{
    TEST_FIXTURE(Key,UpCaseRussianText) {
        wstring text = L"ПРОВЕРКА";
        wstring res = L"ЪЬМЩПЬИЧ";
        CHECK_EQUAL (true, res == k->encrypt(text));
    }
    TEST_FIXTURE(Key,LowCaseRussianText) {
        wstring text = L"текстдлязашифрования";
        wstring res = L"ЭРИИЭПЙЦТЛЦАЯЬМЩКЩЖЦ"; 
        CHECK_EQUAL (true, res == k->encrypt(text));
    }
    TEST_FIXTURE (Key,MixedCaseRussianText) {
        wstring text = L"СмешанныйРегистр";
        wstring res = L"ЬШГПКЩЛТФЬГЪУЭРЗ";
        CHECK_EQUAL (true, res == k->encrypt(text));
    }
    TEST_FIXTURE (Key,EmptyText) {
        wstring text = L"";
        CHECK_THROW (k->encrypt(text),MyException);
    }
    TEST_FIXTURE (Key,DigitsInText) {
        wstring text = L"Циф9ра";
        CHECK_THROW (k->encrypt(text),MyException);
    }
    TEST_FIXTURE (Key,PunctCharInText) {
        wstring text = L"Знак!";
        CHECK_THROW (k->encrypt(text),MyException);
    }
    TEST_FIXTURE (Key,EnglishText) {
        wstring text = L"EnglishLanguage";
        CHECK_THROW (k->encrypt(text),MyException);
    }
    TEST_FIXTURE (Key,SpaceInText) {
        wstring text = L"Пробел обнаружен";
        CHECK_THROW (k->encrypt(text),MyException);
    }
}
SUITE (DecodeTest)
{
    TEST_FIXTURE(Key,UpCaseRussianText) {
        wstring text = L"ЭРИИЭПЙЦТЛЦАЯЬМЩКЩЖЦ";
        wstring res = L"ТЕКСТДЛЯЗАШИФРОВАНИЯ";
        CHECK_EQUAL (true,res == k->decrypt(text));
    }
    TEST_FIXTURE(Key,LowCaseRussianText) {
        wstring text = L"ъьмщпьич";
        wstring res = L"ПРОВЕРКА";
        CHECK_EQUAL (true,res == k->decrypt(text));
    }
    TEST_FIXTURE (Key,MixedCaseRussianText) {
        wstring text = L"ЬшгПкЩлтФЬгЪуэрЗ";
        wstring res = L"СМЕШАННЫЙРЕГИСТР";
        CHECK_EQUAL (true,res == k->decrypt(text));
    }
    TEST_FIXTURE (Key,EmptyText) {
        wstring text = L"";
        CHECK_THROW (k->decrypt(text),MyException);
    }
    TEST_FIXTURE (Key,DigitsInText) {
        wstring text = L"Циф7ра";
        CHECK_THROW (k->decrypt(text),MyException);
    }
    TEST_FIXTURE (Key,PunctCharInText) {
        wstring text = L"Вопрос?";
        CHECK_THROW (k->decrypt(text),MyException);
    }
    TEST_FIXTURE (Key,EnglishText) {
        wstring text = L"EnglishWords";
        CHECK_THROW (k->decrypt(text),MyException);
    }
    TEST_FIXTURE (Key,SpaceInText) {
        wstring text = L"Привет мир";
        CHECK_THROW (k->decrypt(text),MyException);
    }
}
int main()
{
    return UnitTest::RunAllTests();
}
