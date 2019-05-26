#include "database.h"
#include <QApplication>
<<<<<<< HEAD
=======
#include "../../DB/registros.h"
>>>>>>> 7c7d9ac57fab3e533c8bb1643841a1d7c5976173

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
<<<<<<< HEAD
    Database w;
    w.show();

=======
    Database w;    
    w.show();
>>>>>>> 7c7d9ac57fab3e533c8bb1643841a1d7c5976173
    return a.exec();
}
