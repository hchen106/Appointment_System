#ifndef LOGINUICONTROLLER_H
#define LOGINUICONTROLLER_H

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <vector>

namespace Controller{

    class LoginUIController{
        
        public: 
            LoginUIController(std::string, int, boost::asio::io_service&);

            //~LoginUIController();

            void TcpConnection();

            std::string isVertified(std::string,std::string);
            
            //Provider CreateProvider(){}
        private:
            std::string IP;
            int PORT;
            //boost::shared_ptr<boost::asio::ip::tcp::socket> tcp_socket;
            boost::asio::io_service& io_service_;
            boost::asio::ip::tcp::socket socket_;

    };

    class MainWindowUIController {
        //TODO:
    };

}

#endif