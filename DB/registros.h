#ifndef REGISTROS_H
#define REGISTROS_H

#include<iostream>
#include<fstream>
using namespace std;
class Registros
{
public:    
    char App[51];
    char Category[20];
    float Rating;
    int Review;
    char Size[19];
    char Installs[13];
    char Type[5];
    char Price[8];
    char Content_Rating[11];
    char Genres[41];
    char Last_Updates[19];
    char Current_Ver[21];
    char Android_Ver[21];   


    void get_registro(int pos,Registros *regis){
        fstream files;        
        files.open("BD2.dat",ios::in | ios::binary);
        files.seekg(237*pos,ios::beg);
        files.read((char *)regis, 237);
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