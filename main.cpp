<<<<<<< HEAD
#include "DB/registros.h"
#include "DB/dynamicHashing.h"
=======
#include "Dependencies/registros.h"
#include "DynamicHashing/dynamicHashing.h"
>>>>>>> 7c7d9ac57fab3e533c8bb1643841a1d7c5976173

int main(){
  Registros reg;
  int sizeDocument = reg.getDocumentSize();
  for(int i = 0; i < sizeDocument; i++){
    reg.get_registro(i);
    string app(reg.App);
    insertToTable(reg.App,i);
  }
<<<<<<< HEAD
  reg = searchInTable("Facebook");
  reg.print();
=======
  Registros* search = new Registros;
  search = searchInTable("Twit");
  if(search){search->print();}
  else{cout <<"No se encontro\n";}
>>>>>>> 7c7d9ac57fab3e533c8bb1643841a1d7c5976173
}
