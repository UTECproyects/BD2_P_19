#ifndef REGISTROS_H
#define REGISTROS_H

#include<iostream>
#include<fstream>
using namespace std;
class Registros
{
public:
    char App[50];
    char Category[19];
    float Rating;
    int Review;
    char Size[18];
    char Installs[12];
    char Type[4];
    char Price[7];
    char Content_Rating[10];
    char Genres[40];
    char Last_Updates[18];
    char Current_Ver[20];
    char Android_Ver[20];

    void get_registro(int pos){
        fstream files;
        files.open("DB/BD2.dat",ios::in | ios::binary);
        files.seekg(226*pos,ios::beg);
        files.read((char *)this, 226);
        files.close();
    }

    int getDocumentSize(){
      fstream file;
      file.open("DB/BD2.dat",ios::in | ios::binary);
      file.seekg(0, ios::end);
      int sizeDocument = file.tellg();
      return sizeDocument/226;
    }

    void print(){
      cout<<this->App<<"|"<<this->Category<<"|"<<this->Rating<<"|"<<this->Review<<"|"<<this->Size<<"|"<<this->Installs<<"|";
      cout<<this->Type<<"|"<<this->Price<<"|"<<this->Content_Rating<<"|"<<this->Genres<<"|"<<this->Last_Updates<<"|";
      cout<<this->Current_Ver<<"|"<<this->Android_Ver<<"\n";
    }
};

#endif
