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

    Registros get_registro(int pos){
        fstream files;
        files.open("BD2.dat",ios::in | ios::binary);
    }
};

#endif