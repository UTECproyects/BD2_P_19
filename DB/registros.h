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
};

#endif