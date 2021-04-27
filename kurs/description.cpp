#include <Steganography.h>
Steganography::Steganography (const int&key)
{
    degree = key;
}
unsigned char Steganography::tmask ()
{
    unsigned char text_mask = 0b11111111;
    text_mask<<=(8-degree);
    return text_mask;
}
unsigned char Steganography::imask ()
{
    unsigned char img_mask = 0b11111111;
    img_mask>>=degree;
    img_mask<<=degree;
    return img_mask;
}
int Steganography::Concealment (const string&bmp_path,const string&hidden_path)
{
    fstream bmp;
    fstream hidden;
    bmp.open (bmp_path,fstream::out| fstream::in | fstream::binary);
    hidden.open (hidden_path,fstream::in|fstream::binary);
    hidden.seekg(0,ios::end);
    int hiddensize = hidden.tellg();
    cout<<"Размер зашифрованного сообщения (в байтах) = "<<hiddensize<<endl;
    hidden.seekg(0);
    bmp.seekg(54);
    unsigned char Text;
    unsigned char Image;
    unsigned char TextByte;
    unsigned char ImageByte;
    for (int i=0; i<hiddensize; i++) {
        hidden.read (reinterpret_cast<char*>(&Text),sizeof(unsigned char));
        for (int i=0; i<8; i+=degree) {
            bmp.read(reinterpret_cast <char*>(&Image), sizeof(char));
            bmp.seekg(-1,fstream::cur);
            ImageByte = Image&imask();
            TextByte = Text&tmask();
            TextByte >>= (8-degree);
            ImageByte |= TextByte;
            bmp.write (reinterpret_cast <char*>(&ImageByte), sizeof(char));
            Text<<=degree;
        }
    }
    bmp.close ();
    hidden.close ();
    return 0;
}
int Steganography::Extraction (const string&bmp_path,const string&hidden_path,const int&hiddensize)
{
    fstream bmp;
    fstream hidden;
    bmp.open(bmp_path,fstream::in | fstream::binary);
    hidden.open(hidden_path,fstream::out | fstream::binary);
    unsigned char Image;
    unsigned char ImageByte;
    bmp.seekg(54);
    unsigned char image_mask = ~imask();
    for (int i=0; i<hiddensize; i++) {
        unsigned char Symbol = 0;
        for (int i=0; i<8; i+=degree) {
            bmp.read(reinterpret_cast <char*>(&Image),sizeof(char));
            ImageByte = Image&image_mask;
            Symbol<<=degree;
            Symbol |= ImageByte;
        }
        hidden.write (reinterpret_cast<char*>(&Symbol),sizeof(unsigned char));
    }
    bmp.close ();
    hidden.close ();
    return 0;
}
