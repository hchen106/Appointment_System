#include "tcpConnection.h"

tcpConnection::tcpConnection(boost::asio::io_service& io_service, boost::asio::ssl::context& context) : socket_(io_service), tcp_socket(std::move(socket_),context) {

}

tcpConnection::pointer tcpConnection::create(boost::asio::io_service& io_service, boost::asio::ssl::context& context_) {

    return tcpConnection::pointer(new tcpConnection(io_service,context_));
}

ip::tcp::socket& tcpConnection::socket() {
    return socket_;
}