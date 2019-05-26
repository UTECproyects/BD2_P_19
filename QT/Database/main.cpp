#include "database.h"
#include <QApplication>
#ifndef QTapp_h
    #define QTapp_h  "../../"
#endif
#include "../../Dependencies/registros.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    Database w;    
    w.show();
    return a.exec();
}
