#ifndef CLIENT_H
#define CLIENT_H


#include <iostream>
#include <string>
#include "src/view/UI.h"

class client {

    public:
        client(std::string,std::string);

    private:
        std::string id;
        std::string name;



};


#endif