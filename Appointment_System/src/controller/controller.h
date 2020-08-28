#ifndef LOGINUICONTROLLER_H
#define LOGINUICONTROLLER_H

#include <iostream>
#include <string>
#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <boost/asio/ssl.hpp>
#include <vector>
#include "src/model/tcpConnection.h"
#include <string>
#include <json/json.h>
#include <QStandardItem>
#include <QString>
#include <QStandardItemModel>
#include <QTableView>

namespace Controller{

    class addClientController {

        public: 
            addClientController(tcpConnection::pointer,std::string);

            bool sendInformation(std::string, std::string, std::string, std::string, std::string, std::string, std::string);

        private: 
            tcpConnection::pointer new_connection; 
            std::string loginID;
    } ;

    class MainWindowUIController {
        //TODO:
        public: 
            MainWindowUIController(tcpConnection::pointer,std::string);

            //~LoginUIController();
            //Provider CreateProvider(){}
            void closeConnection();
            std::vector<Json::Value> load();
            std::string read_message();


            Controller::addClientController* createAddClientController();
        private:
            //boost::shared_ptr<boost::asio::ip::tcp::socket> tcp_socket;
            //boost::asio::io_service& io_service_;
            //boost::asio::ip::tcp::socket socket_;
            tcpConnection::pointer new_connection;
            std::string loginID;
            //boost::asio::ssl::stream<boost::asio::ip::tcp::socket> tcp_socket;
    };

    class LoginUIController{
        
        public: 
            LoginUIController(std::string, int, boost::asio::io_service&, boost::asio::ssl::context&);

            //~LoginUIController();

            void TcpConnection();

            void closeConnection();

            Controller::MainWindowUIController* createMainWindowController();
            
            std::string isVertified(std::string,std::string);
            
            //Provider CreateProvider(){}
        private:
            std::string IP;
            int PORT;
            //boost::shared_ptr<boost::asio::ip::tcp::socket> tcp_socket;
            std::string loginID;
            tcpConnection::pointer new_connection ;
            boost::asio::io_service& io_service_;
            boost::asio::ip::tcp::socket socket_;
            boost::asio::ssl::context& context_;
            boost::asio::ssl::stream<boost::asio::ip::tcp::socket> tcp_socket;

    };

    

}

#endif