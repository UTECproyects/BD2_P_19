#ifndef DYNAMICHASHING_H
#define DYNAMICHASHING_H
#include "Bucket.h"
using namespace std;

map<string,Bucket*> indexTable;

string hashString(string name){
  long hash = 0;
  for(int i = 0; i < name.size(); i++){
    hash += (int)name[i]*(int)name[i];
  }
  hash = hash%1024;
  string result = bitset< 10 >(hash).to_string();
  return result;
}

void divideBucket(Bucket* oldBucket);

void initializeTable(){
  Bucket* cero = new Bucket("0");
  Bucket* uno = new Bucket("1");
  string hash;
  string last;
  for(int i = 0; i < pow(2,10); i++){
    hash = bitset<10>(i).to_string();
    last = hash[9];
    if(last == "0"){indexTable.insert(pair<string,Bucket*>(hash,cero));}
    else{indexTable.insert(pair<string,Bucket*>(hash,uno));}
  }
}

void insertToTable(string name, long registerNumber){
  string binaryHash = hashString(name);
  if(indexTable.size()==0){initializeTable();}
  if(indexTable[binaryHash]-> getSize()<WIDTH){
    indexTable[binaryHash]-> insert(registerNumber);
  }
  else{
    divideBucket(indexTable[binaryHash]);
    insertToTable(binaryHash,registerNumber);
  }
}

Registros* searchInTable(string name){
  string binaryHash = hashString(name);
  Registros* reg = new Registros;
  if(indexTable[binaryHash]->searchForValue(name,reg)){
    return reg;
  }
  else{
    return NULL;
  }
}

void printTable(){
    for(auto item: indexTable){
      if(item.second)
        cout<< item.first<<" "<<item.second->getName()<<" ";
        item.second->print();
    }
}

void divideBucket(Bucket* oldBucket){
  string Bucketname = oldBucket->getName();
  string newname0 = "0"+Bucketname;
  string newname1 = "1"+Bucketname;
  string hash;
  Bucket* Bucket0 = new Bucket(newname0);
  Bucket* Bucket1 = new Bucket(newname1);
  for(int i = 0; i < pow(2,10); i++){
    hash = bitset<10>(i).to_string();
    if(hash.substr(10-(newname0.size()),newname0.size())==newname0)
      indexTable[hash] = Bucket0;
    else if(hash.substr(10-(newname0.size()),newname0.size())==newname1)
      indexTable[hash] = Bucket1;
  }
  vector<long> values = oldBucket->getValues();
  for(int i = 0;i < values.size();i++){
    Registros reg;
    reg.get_registro(values[i]);
    insertToTable(reg.App,values[i]);
  }
  delete oldBucket;
}

#endif 