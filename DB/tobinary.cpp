#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <cstring>

#include "registros.h"

using namespace std;
vector<string> split_iterator(const string& str){
  vector<string> resultado;

  string::const_iterator itBegin = str.begin();
  string::const_iterator itEnd   = str.end();

  for( string::const_iterator it = itBegin; it!=itEnd; ++it ){
    if( *it == '\"'){
        itBegin = it+1;
        it++;
        for(it;*it!='\"';++it);        
        resultado.push_back(string(itBegin,it--));
        it=it+2;
        itBegin = it+1;
    }else if( *it == ',' ){
      resultado.push_back(string(itBegin,it));
      itBegin = it+1;
    }
  }

  if( itBegin != itEnd )resultado.push_back(string(itBegin,itEnd));

  return resultado;
}

int main(){
    ifstream data("googleplaystore.csv");
    fstream file;
    file.open("BD2.dat", ios::out | ios::app | ios::binary);
    string linea;    
    vector<string> pals;
    Registros registro;
    getline(data,linea);  

    while(!data.eof()){        
        getline(data,linea);        
        pals = split_iterator(linea);            
        strcpy(registro.App,pals[0].substr(0,50).c_str()); 
        strcpy(registro.Category,pals[1].c_str());          
        registro.Rating=stof(pals[2]);                
        registro.Review=stoi(pals[3]);
        strcpy(registro.Size,pals[4].c_str());
        strcpy(registro.Installs,pals[5].c_str());
        strcpy(registro.Type,pals[6].c_str());
        strcpy(registro.Price,pals[7].c_str());
        strcpy(registro.Content_Rating,pals[8].c_str());
        strcpy(registro.Genres,pals[9].c_str());
        strcpy(registro.Last_Updates,pals[10].c_str());
        strcpy(registro.Current_Ver,pals[11].c_str());
        strcpy(registro.Android_Ver,pals[12].c_str());
        file.write((char *)&(registro), 226);


        pals.clear();
    } 
        
}