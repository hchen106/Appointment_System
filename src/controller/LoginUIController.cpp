#include "LoginUIController.h"
#include "DbManager.h"
#include <iostream>

static const QString path = "/home/huihao/Desktop/Login_test/Login/provider.db";

Controller::LoginUIController::LoginUIController(std::string IP , int PORT) {
    //TODO:
    this->IP = IP;
    this->PORT = PORT;
    this->tcp_socket = TcpConnection();

}



int Controller::LoginUIController::TcpConnection() {
    //TODO: 
    return 1;

}


std::string Controller::LoginUIController::isVertified(){
    //TODO:

    return ;
}
