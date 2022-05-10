#ifndef SERVER_H
#define SERVER_H

#endif // !1
#include <QTcpServer>
#include <QTcpSocket>
#include <QDebug>
#include <QVector>

private
    QTcpServer* chatServer;
    QVector<QTcpSocket*>* allClients;

public
   explicit server(Qobject *parent = nullptr);
   void startServer();
   void sendMessageToClients(QString message);

public slots;
   void newClientConnection();
   void socketDisconnected();
   void socketReadyRead();
   void socketStateChanged(QAbstractSocket::SocketState state);

   void server::startServer()
   {
       allClients = new Qvector<Qtcpsocket*>;

       chatServer = QTcpServer();
       chatServer->setMaxPending(10);
       connect (chatServer, SIGNAL(newConnection()), this,
       SLOT(newClientConnection()));

       if (chatServer)
       {
              qDebug() << "Server has started". Listening to port 8001.",
       }
       else
       {
           gDebug() << "Server has failed to start". Error: " + chatServer-
           >errorString();
       }   
   }

    void Server::newClientConnection()
    {
        QTcpSocket* client = chatServer->nextPendingConnection();
        QString ipAddress = client->peerAddress().toString();
        int port = client->peerport();

        connect(client,  &QTcpSocket::disconnected, this,
    &server::socketDisconnected);
         connect(client,  &QTcpSocket::ReadyRead, this,
    &server::socketReadyRead);
         connect(client,  &QTcpSocket::stateChanged, this,
    &server::StateChanged);  

       allClients->push-back(clients);

       qDebug() << "Socket Connected from" + ipAddress + ":" +
    QString::number(port);
    }  
    
    void server::socket Disconnected()
    {
        QTcpSocket* client = qobject_cast<QTCPSocket*>(Qobject::Sender()) 
        QString socketipaddress =client->peerAddress().toString();
        int port = client->peerPort();
        qDebug() << "Socket disconnected from" = socketipAddress + ":" +
        QString::number(port);
    }

    void server::socketReadyRead()
    {
        QTcpSocket* client = qobject_cast<QTCPSocket*>(Qobject::Sender()) 
        QString socketipaddress =client->peerAddress().toString();
        int port = client->peerPort();

        QString data = QString(client->readAll());

        qDebug() << "Message: " + data + " (socketipAddress + ":" +
        QString::number(port); + ")";

        sendMessageToClients(data);
    }
    
    void server::socketStateChanged(QAbstract::SocketState state)
    {
        QTcpSocket* client = qobject_cast<QTCPSocket*>(Qobject::Sender()) 
        QString socketipaddress =client->peerAddress().toString();
        int port = client->peerPort();

        QString desc;

        if (state == QAbstractSocket::UnconnectedState)
              desc = "The socket is not connected. ";
        else if (state == QAbstractSocket::HostLookupState)  
           desc = "The socket is performing host name lookup. ";
        else if (state == QAbstractSocket::ConnectingState)
           desc = "The socket has started establishing connection. ";
        else if (state == QAbstractSocket::ConnectedState)  
           desc = "A connection is established. ";
        else if (state == QAbstractSocket::BoundState)  
           desc = "The socket is bound to an address and a port. ";
        else if (state == QAbstracSocket::ClosingState) 
            desc = "The socket is about to close (data may still be waiting to be written). ";
        else if (state == QAbstracSocket::ListeningState)  
            desc = "For internal use only. ";

        qDebug() << "Socket state changed" (" + socketipAddress + ":" +
        QString::number(port)  + ") : " + desc;  
    }

     void server::sendMessageTClients(QString)
   {
      if  (allClients->size() > 0)
      {
          for (int i = 0; i< allClients->size(); i++)
          {
                if (allClients->at(i)->isOpen() &&allClients->at(i)-
                >isWritable())
                {
                    allClients->at(i)->write(message.toUtf8());
                }

          }
          
    }                     


        

