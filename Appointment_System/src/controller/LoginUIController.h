#ifndef LOGINUICONTROLLER_H
#define LOGINUICONTROLLER_H

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <vector>

namespace Controller{

    class LoginUIController{
        
        public: 
            LoginUIController(std::string, int);

            //~LoginUIController();

            void TcpConnection();

            std::string isVertified(std::string,std::string);
            
            //Provider CreateProvider(){}
        private:
            std::string IP;
            int PORT;
            boost::shared_ptr<boost::asio::ip::tcp::socket> tcp_socket;

    };

    class MainWindowUIController {
        //TODO:
    };

}

#endif