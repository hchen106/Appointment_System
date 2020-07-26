#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <boost/asio.hpp>
#include <vector>
#include "DbManager.h"
//#include <QString>


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

        boost::shared_ptr<boost::asio::ip::tcp::socket> tcp_socket;

        bool vertified(std::string, std::string);

        void wait_for_response();
        std::vector<std::string>  decriptMessage(std::string ); 




};


#endif