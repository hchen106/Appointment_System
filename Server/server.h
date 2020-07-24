#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <boost/asio.hpp>

using namespace boost::asio;

class server {

    //TODO:

    public: 
        server();

        void wait_for_connection();

        std::string read(ip::tcp::socket&);

    private:
        std::map<std::string ,ip::tcp::socket > tcp_socket_list;
        int PORT;



};


#endif