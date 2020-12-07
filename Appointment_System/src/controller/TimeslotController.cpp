#include "controller.h"
#include "src/model/tcpConnection.h"
#include <iostream>
#include <QString>


using namespace boost::asio;


Controller::TimeslotController::TimeslotController(tcpConnection::pointer new_connection_,std::string username) {
    new_connection = new_connection_;
    loginID = username;
}

QString Controller::TimeslotController::getTime() {
    std::string command = loginID + " getTime";
    if(command.length() < 128) {
        std::string extension(128-command.length(), ' ');
        command = command + extension;
    }
    /*
    if(str.length() < 512) {
        std::string extension(512-str.length(), ' ' );
        str = str + extension;
    }
    */
    std::cout << command << std::endl;
    boost::system::error_code error;
    boost::asio::write(new_connection->socket(), boost::asio::buffer(command),error);

    //boost::asio::write(new_connection->socket(), boost::asio::buffer(str),error);
    std::string response = read_message();

    return QString::fromStdString(response);
}

std::string Controller::TimeslotController::read_message() {
    boost::array<char, 512> buf;
    //size_t len = new_connection->socket().read_some(boost::asio::buffer(buf));
    size_t len = boost::asio::read(new_connection->socket(),boost::asio::buffer(buf));
    std::string str = buf.data();
    str = str.substr(0,len);
    //boost::asio::write(new_connection->socket(), boost::asio::buffer("received"));
    return str;
}

bool Controller::TimeslotController::checkBooking(QString date ,int hour,int min) {
    std::string command = loginID + " checkBooking";
    if(command.length() < 128) {
        std::string extension(128-command.length(), ' ');
        command = command + extension;
    }
    /*
    
    */
    std::cout << command << std::endl;
    boost::system::error_code error;
    boost::asio::write(new_connection->socket(), boost::asio::buffer(command),error);

    std::string str = date.toStdString() + " " + std::to_string(hour) + " " + std::to_string(min);
    if(str.length() < 512) {
        std::string extension(512-str.length(), ' ' );
        str = str + extension;
    }
    std::cout << str << std::endl;
    boost::asio::write(new_connection->socket(), boost::asio::buffer(str),error);
    //boost::asio::write(new_connection->socket(), boost::asio::buffer(str),error);
    std::string response = read_message();

    std::cout << response << std::endl;
    if(response == "True") {
        return true;
    }else {
        return false;
    }


    
}