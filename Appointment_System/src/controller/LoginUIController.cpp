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
    this->tcp_socket = boost::shared_ptr<ip::tcp::socket>(new ip::tcp::socket(io_service));
    
    //this->tcp_socket = boost::shared_ptr<ip::tcp::socket> tcp_socket;
    this->tcp_socket->connect(ip::tcp::endpoint(boost::asio::ip::address::from_string(this->IP),this->PORT));
    boost::system::error_code error;
    
    boost::asio::write(*(this->tcp_socket), boost::asio::buffer("hello\n"),error);
    
    if(!error) {
        std::cout << "Successful" << std::endl;
    }else {
        std::cout << "Failed" << error.message() << std::endl;
    }
    
    

}


std::string Controller::LoginUIController::isVertified(std::string username, std::string password){
    //TODO:

    boost::system::error_code error;
    std::string mes = username + " " + password+ "\n";
    boost::asio::write(*(this->tcp_socket), boost::asio::buffer(mes),error);
    if(!error) {
        std::cout << "Successful" << std::endl;
    }else {
        std::cout << "Failed" << error.message() << std::endl;
    }


    return "";
}