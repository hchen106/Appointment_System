#ifndef SERVER_H
#define SERVER_H

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
#include "DbManager.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
//#include <json-c/json.h>
#include <json/json.h>
#include <sstream>
//#include <QString>


using namespace boost::asio;

namespace server {

    class tcp_connection : public boost::enable_shared_from_this<tcp_connection>{
        public: 
            typedef boost::shared_ptr<tcp_connection> pointer;

            static pointer create(boost::asio::io_service&, boost::asio::ssl::context& );

            ip::tcp::socket& socket();

            //ip::tcp::socket get_Socket();
            void handler(tcp_connection::pointer);
            void handle_read(tcp_connection::pointer,size_t);
            void wait_for_response(tcp_connection::pointer);
            void vertify(boost::array<char,128>);
            void temp_handler();

            void send_message(tcp_connection::pointer,std::string);

        private: 
            tcp_connection(boost::asio::io_service&, boost::asio::ssl::context&);
            ip::tcp::socket socket_;
            boost::asio::ssl::stream<ip::tcp::socket> tcp_socket;
            std::string message;
            boost::array<char, 128> buf;
    };

    class tcp_server {
        public: 
            tcp_server(boost::asio::io_service&);
        private: 
            void start_accept();
            void handle_accept(server::tcp_connection::pointer, const boost::system::error_code&);
            std::string get_password() const;
            boost::asio::io_service& io_service_;
            ip::tcp::acceptor acceptor_;
            bool stop;
            typedef std::pair<std::string, tcp_connection::pointer> socket;
            std::vector<socket> socket_list;
            boost::asio::ssl::context context_;
            
    };

    class message_command {
        public:
            message_command();
            void encode();
            std::vector<std::string> decode(std::string);

            std::string get_User();
            std::string get_Command();

        private:
            std::string user;
            std::string command;
    };

    
    




};


#endif