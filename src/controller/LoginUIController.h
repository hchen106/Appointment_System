#ifndef LOGINUICONTROLLER_H
#define LOGINUICONTROLLER_H

#include <iostream>
#include <string>

namespace Controller{

    class LoginUIController{
        
        public: 
            LoginUIController(std::string, int);

            //~LoginUIController();

            int TcpConnection();

            char* isVertified();

            //Provider CreateProvider(){}
        private:
            std::string IP;
            int PORT;


    };

    class MainWindowUIController {
        //TODO:
    };

}

#endif