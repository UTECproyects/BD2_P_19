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

    void get_registro(int pos,Registros *regis){
        fstream files;        
        files.open("BD2.dat",ios::in | ios::binary);
        files.seekg(226*pos,ios::beg);
        files.read((char *)regis, 226);
        files.close();
    }
};

#endif