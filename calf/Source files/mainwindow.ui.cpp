#ifndef  MAINWINDOW_H
#define MAINWINDOW_H

#endif // ! MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTcpSocket>

private:
    Ui::MainWindow *ui;
    bool connectedToHost;
    QTcpSocket* socket;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent) ,
    ui(new UI:MaimWindow)
{
    ui->setupUi(this);
    connectedtoHost = false
}
void MainWindow::on_connectButton_clicked()
{
    if(!connectedToHost)
    {
        socket = new QTcpsocket();

        connect(socket,SIGNAL(connected()), this,
        SLOT(socketConnected()));
        connect(socket,SIGNAL(disconnected()), this,
        SLOT(socketDisconnected()));
        connect(socket,SIGNAL(readyRead()), this,
        SLOT(socketReadyRead()));

        socket->connectToHost("127.0.0.1", 8001;

    }
    else
    {
        QString name = ui->nameInput->text();
        socket->write("<font colour="Orange" ">" + name.toUtf8() + " has
        left the chat room.</font>");

        socket->disconnectedFromHost ();
    }    
}


void MainWindow::socketConnected()
{
    qDebug() << "Connected to server. ";

    printMessage("font colour = "Green">Connected to server.</font>") ;

    QString name = ui->nameInput->text();
    socket->write("<font colour="Purple"">" + name.toUtf8() + " has joined the chatroom.</font>");
    the chat room.</font>");

    ui->connectButton->setTetx("Disconnect") ;
    connetedToHost = true;
}

void MainWindow::socketDisconneted ()
{
    qDebug() << "Disconnected from server. ";

    printMessage("font colour = "Red">Disconnected from server.</font>") ;

    ui->connectButton->setText("Connect") ;
    connectedToHost = false;
}


void MainWindow::socketReadyRead()
{
    ui->chatDisplay->append(socket->readAll()) ;
}    

void MainWindow::printMessage(QString message)
{
    ui->chatDisplay->append(socket->readAll()) ;


void MainWindow::on_sendButton_clicked()
{
    QString name = ui->nameInput->text () ;
    QString message = ui->messageInput->text () ;
    socket->write("font color="Blue">" + name.toUtf8() + "</font>: " + message.toUtf8()) ;

    ui->messageInput->clear();
}    
