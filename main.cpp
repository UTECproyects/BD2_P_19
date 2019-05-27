#include "Dependencies/registros.h"
#include "DynamicHashing/dynamicHashing.h"
#include "Random_File/Querys/query.h"

int main(){
  string q = "select * from DB where App = 'Gas Station' ;";
  query obj;
  auto bk=obj.ejecutar_consulta_recibida(q);
  cout<<bk.first->App<<endl;
  /*
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
  */
}
