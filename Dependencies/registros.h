#ifndef REGISTROS_H
#define REGISTROS_H

#include<iostream>
#include<fstream>

#ifndef QTapp_h
  #define path ""
#else
    #define path QTapp_h
#endif

using namespace std;
class Registros
{
public:
    char App[51];
    char Category[20];
    float Rating;
    int Review;
    char Size[19];
    char Installs[15];
    char Type[5];
    char Price[8];
    char Content_Rating[11];
    char Genres[41];
    char Last_Updates[19];
    char Current_Ver[21];
    char Android_Ver[21];

    void get_registro(int pos){
        fstream files;
        files.open(std::string(path)+"Dependencies/BD2.dat",ios::in | ios::binary);
        files.seekg(239*pos,ios::beg);
        files.read((char *)this, 239);
        files.close();
    }

    int getDocumentSize(){
      fstream file;
      file.open(std::string(path)+"Dependencies/BD2.dat",ios::in | ios::binary);
      file.seekg(0, ios::end);
      int sizeDocument = file.tellg();
      return sizeDocument/239;
    }

    void print(){
      cout<<this->App<<"|"<<this->Category<<"|"<<this->Rating<<"|"<<this->Review<<"|"<<this->Size<<"|"<<this->Installs<<"|";
      cout<<this->Type<<"|"<<this->Price<<"|"<<this->Content_Rating<<"|"<<this->Genres<<"|"<<this->Last_Updates<<"|";
      cout<<this->Current_Ver<<"|"<<this->Android_Ver<<"\n";
    }
};

#endif
