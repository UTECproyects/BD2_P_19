#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <bitset>
#include <fstream>
#include <cmath>
#include "registros.h"
#define WIDTH 40
using namespace std;


class Block{
private:
  string name;
  vector<long> values;
public:
  Block(string name):name(name){}

  string getName(){return name;}

  int getSize(){return values.size();}

  void print(){
    for(auto item:values){cout <<item<<" -> ";}
    cout <<"\n";
  }

  Registros searchForValue(string name){
    Registros reg;
    for(int i = 0; i < values.size();i++){
      reg.get_registro(values[i]);
      if(reg.App==name){return reg;}
    }
  }

  vector<long> getValues(){return values;}

  bool insert(long registerNumber){
    values.push_back(registerNumber);
    return true;
  }

};
