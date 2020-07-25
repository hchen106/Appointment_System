#include "LoginUIController.h"
#include <iostream>


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
    return "";
}
