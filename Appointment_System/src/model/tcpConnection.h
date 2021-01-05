#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <iostream>
#include <boost/asio.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/shared_ptr.hpp> 
#include <boost/bind/bind.hpp>
#include <boost/array.hpp>
#include <boost/asio/ssl.hpp>
#include <cstdlib>
#include <functional>
#include <string>
#include <vector>

using namespace boost::asio;

class tcpConnection : public boost::enable_shared_from_this<tcpConnection>{


    public:
        typedef boost::shared_ptr<tcpConnection> pointer;

        static pointer create(boost::asio::io_service&, boost::asio::ssl::context& );

        ip::tcp::socket& socket();

    private:

        tcpConnection(boost::asio::io_service&, boost::asio::ssl::context&);
        ip::tcp::socket socket_;
        boost::asio::ssl::stream<ip::tcp::socket> tcp_socket;
        std::string message;
        boost::array<char, 128> buf;


};


#endif