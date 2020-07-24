#ifndef LOGINUICONTROLLER_H
#define LOGINUICONTROLLER_H

#include <iostream>
#include <string>
#include <boost/asio.hpp>

namespace Controller{

    class LoginUIController{
        
        public: 
            LoginUIController(std::string, int);

            //~LoginUIController();

            void TcpConnection();

            std::string isVertified();

            //Provider CreateProvider(){}
        private:
            std::string IP;
            int PORT;
            int tcp_socket;

    };

    class MainWindowUIController {
        //TODO:
    };

}

#endif