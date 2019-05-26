#include "Block.h"
using namespace std;

map<string,Block*> indexTable;

string hashString(string name){
  long hash = 0;
  for(int i = 0; i < name.size(); i++){
    hash += (int)name[i]*(int)name[i];
  }
  hash = hash%1024;
  string result = bitset< 10 >(hash).to_string();
  return result;
}

void divideBlock(Block* oldblock);

void initializeTable(){
  Block* cero = new Block("0");
  Block* uno = new Block("1");
  string hash;
  string last;
  for(int i = 0; i < pow(2,10); i++){
    hash = bitset<10>(i).to_string();
    last = hash[9];
    if(last == "0"){indexTable.insert(pair<string,Block*>(hash,cero));}
    else{indexTable.insert(pair<string,Block*>(hash,uno));}
  }
}

void insertToTable(string name, long registerNumber){
  string binaryHash = hashString(name);
  if(indexTable.size()==0){initializeTable();}
  if(indexTable[binaryHash]-> getSize()<WIDTH){
    indexTable[binaryHash]-> insert(registerNumber);
  }
  else{
    divideBlock(indexTable[binaryHash]);
    insertToTable(binaryHash,registerNumber);
  }
}

Registros searchInTable(string name){
  string binaryHash = hashString(name);
  Registros reg = indexTable[binaryHash]->searchForValue(name);
  return reg;
}

void printTable(){
    for(auto item: indexTable){
      if(item.second)
        cout<< item.first<<" "<<item.second->getName()<<" ";
        item.second->print();
    }
}

void divideBlock(Block* oldblock){
  string blockname = oldblock->getName();
  string newname0 = "0"+blockname;
  string newname1 = "1"+blockname;
  string hash;
  Block* block0 = new Block(newname0);
  Block* block1 = new Block(newname1);
  for(int i = 0; i < pow(2,10); i++){
    hash = bitset<10>(i).to_string();
    if(hash.substr(10-(newname0.size()),newname0.size())==newname0)
      indexTable[hash] = block0;
    else if(hash.substr(10-(newname0.size()),newname0.size())==newname1)
      indexTable[hash] = block1;
  }
  vector<long> values = oldblock->getValues();
  for(int i = 0;i < values.size();i++){
    Registros reg;
    reg.get_registro(values[i]);
    insertToTable(reg.App,values[i]);
  }
  delete oldblock;
}