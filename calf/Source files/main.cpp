#include <QCoreApplication>
#include "server.h"

 int main(int argc, const char** argv) {
    return 0;
}
     QCoreApplication a(argc, argv);

     server* myServer = new server();
     myServer->startServer();

     return a.exec();
}


