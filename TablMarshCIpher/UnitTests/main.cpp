#include <UnitTest++/UnitTest++.h>
#include "MyClass.h"
#include "Exception.h"
SUITE (CheckKeyTest)
{
    TEST (WorkKey) {
        wstring key = L"10";
        CHECK_EQUAL (true,MyException::CheckKey(key));
    }
    TEST (EmptyKey) {
        wstring key = L"";
        CHECK_THROW (MyException::CheckKey(key),MyException);
    }
    TEST (NegativeKey) {
        wstring key = L"-10";
        CHECK_THROW (MyException::CheckKey(key),MyException);
    }
    TEST (NullKey) {
        wstring key = L"0";
        CHECK_THROW (MyException::CheckKey(key),MyException);
    }
    TEST (CharInKey) {
        wstring key = L"1test0";
        CHECK_THROW (MyException::CheckKey(key),MyException);
    }
    TEST (CharKey) {
        wstring key = L"Test";
        CHECK_THROW (MyException::CheckKey(key),MyException);
    }
    TEST (PunctCharInKey) {
        wstring key = L"1!0";
        CHECK_THROW (MyException::CheckKey(key),MyException);
    }
    TEST (SpaceInKey) {
        wstring key = L"1 0";
        CHECK_THROW (MyException::CheckKey(key),MyException);
    }
}
struct TESTKEY {
    int key = 3;
    MarshCipher *t;
    TESTKEY ()
    {
        t = new MarshCipher (L"5");
    }
    ~TESTKEY ()
    {
        delete t;
    }
};
SUITE (TextCheckTest)
{
    TEST_FIXTURE (TESTKEY,CorrectEngText) {
        wstring text = L"EnglishText";
        CHECK_EQUAL (true,MyException::CheckText(text,key));
    }
    TEST_FIXTURE (TESTKEY,CorrectRussianText) {
        wstring text = L"РусскийТекст";
        CHECK_EQUAL (true,MyException::CheckText(text,key));
    }
    TEST_FIXTURE (TESTKEY,MixedLanguageText) {
        wstring text = L"РусскийText";
        CHECK_THROW(MyException::CheckText(text,key),MyException);
    }
    TEST_FIXTURE (TESTKEY,DigitsInText) {
        wstring text = L"hell25o";
        CHECK_THROW (MyException::CheckText(text,key),MyException);
    }
    TEST_FIXTURE (TESTKEY,PunctCharInText) {
        wstring text = L"hel,lo";
        CHECK_THROW (MyException::CheckText(text,key),MyException);
    }
    TEST_FIXTURE (TESTKEY,SpaceInText) {
        wstring text = L"Привет Мир";
        CHECK_THROW (MyException::CheckText(text,key),MyException);
    }
    TEST_FIXTURE (TESTKEY,ShortText) {
        wstring text = L"ok";
        CHECK_THROW (MyException::CheckText(text,key),MyException);
    }
    TEST_FIXTURE (TESTKEY,EmptyText) {
        wstring text = L"";
        CHECK_THROW (MyException::CheckText(text,key),MyException);
    }
}
SUITE (EncryctTest)
{
    TEST_FIXTURE (TESTKEY,EnglishLowCaseText) {
        wstring text = L"helloguys";
        wstring res = L"olslyeuhg";
        CHECK_EQUAL (true,res == t->Encryct(text));
    }
    TEST_FIXTURE (TESTKEY,EnglishUpCaseText) {
        wstring text = L"HELLOWORLD";
        wstring res = L"ODLLLREOHW";
        CHECK_EQUAL (true,res == t->Encryct(text));
    }
    TEST_FIXTURE (TESTKEY,EnglishMixedCaseText) {
        wstring text = L"HaveaNiceDay";
        wstring res = L"aDeevcaiyHNa";
        CHECK_EQUAL (true,res == t->Encryct(text));
    }
    TEST_FIXTURE (TESTKEY,RussianLowCaseText) {
        wstring text = L"незнаючтонаписать";
        wstring res = L"ананосзтиечпьнюат";
        CHECK_EQUAL (true,res == t->Encryct(text));
    }
    TEST_FIXTURE (TESTKEY,RussianUpCaseText) {
        wstring text = L"ПРОВЕРКАБУКВ";
        wstring res = L"ЕУВБОАРКВПРК";
        CHECK_EQUAL (true,res == t->Encryct(text));
    }
    TEST_FIXTURE (TESTKEY,RussianMixedCaseText) {
        wstring text = L"ПриветМир";
        wstring res = L"евриирМПт";
        CHECK_EQUAL (true,res == t->Encryct(text));
    }
}
SUITE (DecryctTest)
{
    TEST_FIXTURE (TESTKEY,EnglishLowCaseText) {
        wstring text = L"olslyeuhg";
        wstring res = L"helloguys";
        CHECK_EQUAL (true,res == t->Decryct(text));
    }
    TEST_FIXTURE (TESTKEY,EnglishUpCaseText) {
        wstring text = L"ODLLLREOHW";
        wstring res = L"HELLOWORLD";
        CHECK_EQUAL (true,res == t->Decryct(text));
    }
    TEST_FIXTURE (TESTKEY,EnglishMixedCaseText) {
        wstring text = L"OemraeGv";
        wstring res = L"GameOver";
        CHECK_EQUAL (true,res == t->Decryct(text));
    }
    TEST_FIXTURE (TESTKEY,RussianLowCaseText) {
        wstring text = L"ананосзтиечпьнюат";
        wstring res = L"незнаючтонаписать";
        CHECK_EQUAL (true,res == t->Decryct(text));
    }
    TEST_FIXTURE (TESTKEY,RussianUpCaseText) {
        wstring text = L"ЕУВБОАРКВПРК"; 
        wstring res = L"ПРОВЕРКАБУКВ";
        CHECK_EQUAL (true,res == t->Decryct(text));
    }
    TEST_FIXTURE (TESTKEY,RussianMixedCaseText) {
        wstring text = L"тяяасМееДо";
        wstring res = L"ДесятоеМая";
        CHECK_EQUAL (true,res == t->Decryct(text));
    }
}
int main()
{
    return UnitTest::RunAllTests();
}
