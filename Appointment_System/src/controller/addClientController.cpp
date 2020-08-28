#include "controller.h"
#include "src/model/tcpConnection.h"
#include <iostream>



using namespace boost::asio;


Controller::addClientController::addClientController(tcpConnection::pointer new_connection_,std::string username) {
    new_connection = new_connection_;
    loginID = username;
}

bool Controller::addClientController::sendInformation(std::string name, std::string email, std::string address, std::string phone, std::string birthday, std::string provider, std::string providerID ) {
    
    Json::Value jsonPacket;
    jsonPacket["name"] = name;
    jsonPacket["email"] = email;
    jsonPacket["address"] = address;
    jsonPacket["phone"] = phone;
    jsonPacket["birthday"] = birthday;
    jsonPacket["provider"] = provider;
    jsonPacket["providerid"] = providerID;

    Json::FastWriter fastWriter;
    std::string str = fastWriter.write(jsonPacket); 

    std::string command = loginID + " addClient";
    if(command.length() < 128) {
        std::string extension(128-command.length(), ' ');
        command = command + extension;
    }

    if(str.length() < 512) {
        std::string extension(512-str.length(), ' ' );
        str = str + extension;
    }
    std::cout << command << std::endl;
    boost::system::error_code error;
    boost::asio::write(new_connection->socket(), boost::asio::buffer(command),error);

    boost::asio::write(new_connection->socket(), boost::asio::buffer(str),error);
    std::cout << "done" << std::endl;

    if(error) {
        return false;
    }else {
        return true;
    }
}

