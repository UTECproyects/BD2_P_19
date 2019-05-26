#include "DB/registros.h"
#include "DB/dynamicHashing.h"

int main(){
  Registros reg;
  int sizeDocument = reg.getDocumentSize();
  cout <<sizeDocument<<"\n";
  for(int i = 0; i < sizeDocument; i++){
    reg.get_registro(i);
    string app(reg.App);
    insertToTable(reg.App,i);
  }
  reg = searchInTable("Facebook");
  reg.print();
}
