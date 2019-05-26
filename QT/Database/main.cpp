#include "database.h"
#include <QApplication>
#include "../../DB/registros.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Database w;    
    w.show();
    return a.exec();
}
