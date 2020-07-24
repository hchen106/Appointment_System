#include "server.h"



server::server() {
    this->PORT = 8001;
    this->wait_for_connection();


}


void server::wait_for_connection() {
    boost::asio::io_service io_service;
    ip::tcp::acceptor acceptor(io_service, ip::tcp::endpoint(ip::tcp::v4(), this->PORT));

    ip::tcp::socket tcp_socket(io_service);

    acceptor.accept(tcp_socket);

    std::cout << "Accept"  << std::endl;
    
    std::string message = read(tcp_socket);

    std::cout << message << std::endl;



}


std::string server::read(ip::tcp::socket & socket){
    streambuf buf;
    read_until(socket, buf, "\n");
    std::string data = buffer_cast<const char*>(buf.data());
    return data;
}




//TODO: