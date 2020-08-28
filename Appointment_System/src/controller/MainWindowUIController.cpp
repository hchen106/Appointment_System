#include "controller.h"
#include "src/model/tcpConnection.h"
#include <iostream>



using namespace boost::asio;


Controller::MainWindowUIController::MainWindowUIController(tcpConnection::pointer connection, std::string username)
    : new_connection(connection), loginID(username){

    
    
}
std::string Controller::MainWindowUIController::read_message() {
    boost::array<char, 512> buf;
    //size_t len = new_connection->socket().read_some(boost::asio::buffer(buf));
    size_t len = boost::asio::read(new_connection->socket(),boost::asio::buffer(buf));
    std::string str = buf.data();
    str = str.substr(0,len);
    //boost::asio::write(new_connection->socket(), boost::asio::buffer("received"));
    return str;
}

Controller::addClientController* Controller::MainWindowUIController::createAddClientController() {
    Controller::addClientController *controller = new Controller::addClientController(new_connection, loginID);
    return controller;
}

std::vector<Json::Value> Controller::MainWindowUIController::load() {
    std::string command = loginID + " loadall";
    std::cout << command << std::endl;
    boost::system::error_code error;
    boost::asio::write(new_connection->socket(), boost::asio::buffer(command),error);
    bool end = false;
    std::vector<std::string> vec;
    std::vector<Json::Value> json_vec;
    while(!end) {
        if(!error) {
            //std::cout << "Successfully sent command" << std::endl;
            
            boost::array<char, 512> buf;
            boost::asio::streambuf buffer;
            //std::size_t len = boost::asio::read(new_connection->socket(),boost::asio::buffer(buf));
            std::string str = read_message();
           // size_t len = new_connection->socket().read_some(boost::asio::buffer(buf), error);
            //std::cout.write(buf.data(), len) << std::endl<<std::endl;
            //std::cout << len <<std::endl;
            //std::string str = buf.data();
            //str = str.substr(0,len);
            std::cout << str << std::endl << std::endl;
            //std::cout << len << std::endl;
            std::string extendsion(512-3, ' ');
            std::string ed = "End" + extendsion;
            //std::cout << ed.size() << std::endl;
            
            if(str == ed) {
                end = true;
            }else {
               // boost::asio::write(new_connection->socket(), boost::asio::buffer("received"));
                Json::Value jsonPacket;
                std::stringstream(str) >> jsonPacket;
                std::cout << jsonPacket << std::endl;


                json_vec.push_back(jsonPacket);
                //vec.push_back(str);
                // Json::Value jsonPacket;
                // std::stringstream(str) >> jsonPacket;
                // std::cout << jsonPacket << std::endl;

                
            }
        }
    }

    /*
    for(int i =0; i < vec.size(); i++) {
        Json::Value jsonPacket;
        std::stringstream(vec[i]) >> jsonPacket;
        std::cout << jsonPacket << std::endl;
        json_vec.push_back(jsonPacket);
        
        //QString qs = QString::fromStdString(vec[i]);
        //QStandardItem *item = new QStandardItem(qs);
        //model.insertRow(0,item);
    }
    */
    return json_vec;
}


void Controller::MainWindowUIController::closeConnection() {
    
    std::string command = "server logout";
    std::cout << command << std::endl;
    boost::system::error_code error;
    boost::asio::write(new_connection->socket(), boost::asio::buffer(command),error);
    
}



