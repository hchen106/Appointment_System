#include "LoginUIController.h"
#include <iostream>

using namespace boost::asio;


Controller::LoginUIController::LoginUIController(std::string IP , int PORT) {
    //TODO:
    this->IP = IP;
    this->PORT = PORT;
    this->TcpConnection();


}



void Controller::LoginUIController::TcpConnection() {
    //TODO: 
    boost::asio::io_service io_service;
    ip::tcp::socket tcp_socket(io_service);
    tcp_socket.connect(ip::tcp::endpoint(boost::asio::ip::address::from_string("10.0.0.89"),this->PORT));
    boost::system::error_code error;
    
    boost::asio::write(tcp_socket, boost::asio::buffer("hello\n"),error);
    
    if(!error) {
        std::cout << "Successful" << std::endl;
    }else {
        std::cout << "Failed" << error.message() << std::endl;
    }
    

    

}


std::string Controller::LoginUIController::isVertified(){
    //TODO:
    return "";
}