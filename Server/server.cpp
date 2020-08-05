#include "server.h"


//static const QString path = "/home/matthew779/appointment_system/Appointment_System/Server/provider.db";
static const QString path = "/Users/xinhaoxiao/Desktop/document/Appointment_System/Server/provider.db";

using namespace server;

tcp_server::tcp_server(boost::asio::io_service& io_service): 
    io_service_(io_service), acceptor_(io_service, ip::tcp::endpoint(ip::tcp::v4(), 8003)) {
    stop = true;
    
    start_accept();
    std::cout << "Server End" << std::endl;
}

void tcp_server::start_accept() {
    tcp_connection::pointer new_connection = tcp_connection::create(io_service_);
    //socket_list.push_back(new_connection);
    std::cout << "Waiting for connection....." << std::endl;
    //while(stop) {
        acceptor_.async_accept(new_connection->socket(), boost::bind(&tcp_server::handle_accept,this,new_connection,
            boost::asio::placeholders::error));
        std::cout << "connection" << std::endl;
    //}

    
    
}

void tcp_server::handle_accept(server::tcp_connection::pointer new_connection, const boost::system::error_code& error) {
    if(!error) {
        std::cout << "Connection Accepted" << std::endl;
        stop = false;
        
        new_connection->wait_for_response(new_connection);
        
        start_accept();
    }


}

tcp_connection::pointer tcp_connection::create(boost::asio::io_service& io_service) {
    return tcp_connection::pointer(new tcp_connection(io_service));
}

ip::tcp::socket& tcp_connection::socket() {
    return socket_;
}

void tcp_connection::wait_for_response(server::tcp_connection::pointer new_connection) {

    //Send a sample message back to clients when they first connected to server. 

    

    //boost::asio::async_write(socket_, boost::asio::buffer("Hello"), 
    //    boost::bind(&tcp_connection::handle_write, shared_from_this()));
    

    
    //socket_list.push_back(("1",new_connection->socket()));
    
    
    boost::system::error_code error;
    //size_t len = new_connection->socket().read_some(boost::asio::buffer(buf));
    new_connection->socket().async_read_some(boost::asio::buffer(buf),boost::bind(&tcp_connection::handle_write,shared_from_this()
        ,new_connection));
    //boost::asio::async_write(new_connection->socket(), boost::asio::buffer("Approved"), 
    //    boost::bind(&tcp_connection::handler, shared_from_this()));
    std::cout << "Sent" << std::endl;
    
}

void tcp_connection::handler() {

}

void tcp_connection::handle_write(server::tcp_connection::pointer new_connection) {


    message_command mes;
    std::string str = buf.data();
    std::vector<std::string> list = mes.decode(str);
    //std::cout << mes.get_User() << " " << mes.get_Command() << std::endl;
    
    if(mes.get_Command() == "vertify") {
        std::string username = list[2];
        std::string pass = list[3];

        DbManager db(path);
        QString loginID = QString::fromStdString(username);
        //std::cout << loginID.toUtf8().constData() << std::endl;
        QString password = QString::fromStdString(pass);
        if(db.loginAccount(loginID, password)) {
            std::cout << "Login Successfullly" << std::endl;
            boost::asio::async_write(new_connection->socket(), boost::asio::buffer("Successful"), 
                boost::bind(&tcp_connection::handler, shared_from_this()));
            //QMessageBox::information(this, "Login", "Login Successful");
        }else{
            boost::asio::async_write(new_connection->socket(), boost::asio::buffer("Failed"), 
                boost::bind(&tcp_connection::handler, shared_from_this()));
            std::cout << "LoginID or Password is incorrect" << std::endl;
            
        }
            
    }
    
    
}

void tcp_connection::vertify(boost::array<char,128> buff) {

    std::cout << buff.data() << std::endl;
    
    
}

tcp_connection::tcp_connection(boost::asio::io_service& io_service) : socket_(io_service) {

}


message_command::message_command() {

}

std::vector<std::string> message_command::decode(std::string str) {
    std::vector<std::string> list; 
    std::string word = "";
    std::cout << str << std::endl;
    for (auto x : str) { 
        if (x == ' ') { 
            list.push_back(word);
            word = ""; 
            
        } else{ 
            word = word + x; 
            
        } 
    }  
    list.push_back(word);

    user = list[0];
    command = list[1];
    return list;
}

std::string message_command::get_User() {
    return user;
}

std::string message_command::get_Command() {
    return  command;
}

