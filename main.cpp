#include "Dependencies/registros.h"
#include "DynamicHashing/dynamicHashing.h"

int main(){
  Registros reg;
  int sizeDocument = reg.getDocumentSize();
  for(int i = 0; i < sizeDocument; i++){
    reg.get_registro(i);
    string app(reg.App);
    insertToTable(reg.App,i);
  }
  Registros* search = new Registros;
  search = searchInTable("Twitter");
  if(search){search->print();}
  else{cout <<"No se encontro\n";}
}
