#include "LoginUIController.h"
#include <iostream>


using namespace boost::asio;


Controller::LoginUIController::LoginUIController(std::string IP , int PORT, boost::asio::io_service& io_service) 
    : io_service_(io_service), socket_(io_service_) {
    //TODO:
    this->IP = IP;
    this->PORT = PORT;
    //boost::asio::io_service io_service;
    this->TcpConnection();


}



void Controller::LoginUIController::TcpConnection() {
    //TODO: 
    //boost::asio::io_service io_service;
    //this->tcp_socket = boost::shared_ptr<ip::tcp::socket>(new ip::tcp::socket(io_service));
    
    //this->tcp_socket = boost::shared_ptr<ip::tcp::socket> tcp_socket;
    //this->tcp_socket->connect(ip::tcp::endpoint(boost::asio::ip::address::from_string(this->IP),this->PORT));
    socket_.connect(ip::tcp::endpoint(boost::asio::ip::address::from_string(this->IP),this->PORT));
    //boost::system::error_code error;
    

    //boost::array<char, 128> buf;
    //boost::system::error_code error;

    //size_t len = socket_.read_some(boost::asio::buffer(buf), error);
    
    
    
    //boost::array<char, 128> buf;
    //boost::asio::streambuf buffer;
    //std::size_t len = boost::asio::read(socket_,boost::asio::buffer(buf));
    //std::cout.write(buf.data(), len) << std::endl;
    
    //std::cout << buffer << std::endl;

    //boost::asio::write(*(this->tcp_socket), boost::asio::buffer("hello\n"),error);
    /*
    if(!error) {
        std::cout << "Successful" << std::endl;
    }else {
        std::cout << "Failed" << error.message() << std::endl;
    }
    */
   std::cout << "Connected" << std::endl;
    

}


std::string Controller::LoginUIController::isVertified(std::string username, std::string password){
    //TODO:
    
    boost::system::error_code error;
    std::string mes = " " + username + " " + password;
    std::string command = "server vertify" + mes;
    boost::asio::write(socket_, boost::asio::buffer(command),error);
    if(!error) {
        std::cout << "Successful" << std::endl;
    }else {
        std::cout << "Failed" << error.message() << std::endl;
    }
    
    boost::array<char, 128> buf;
    boost::asio::streambuf buffer;
    //std::size_t len = boost::asio::read(socket_,boost::asio::buffer(buf));
    size_t len = socket_.read_some(boost::asio::buffer(buf), error);
    std::cout.write(buf.data(), len) << " Logined."<< std::endl;
    
    /*
    boost::asio::write(socket_, boost::asio::buffer(mes),error);
    if(!error) {
        std::cout << "Successful" << std::endl;
    }else {
        std::cout << "Failed" << error.message() << std::endl;
    }

    */

    
    return "";
}
