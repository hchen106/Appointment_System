#include "server.h"


static const QString path = "/home/matthew779/appointment_system/Appointment_System/Server/provider.db";

server::server() {
    this->PORT = 8002;
    this->wait_for_connection();


}


void server::wait_for_connection() {
    boost::asio::io_service io_service;
    std::cout <<  ip::address_v4() << std::endl;
    ip::tcp::acceptor acceptor(io_service, ip::tcp::endpoint(ip::address_v4(), this->PORT));
    this->tcp_socket = boost::shared_ptr<ip::tcp::socket>(new ip::tcp::socket(io_service));
    

    acceptor.accept(*(this->tcp_socket));
    
    
    std::cout << "Accept"  << std::endl;
    
    std::string message = read(*(this->tcp_socket));

    std::cout << message ;
    
    this->wait_for_response();
}

void server::wait_for_response() {
    while(true) {
        std::cout << "in function" << std::endl;
        std::string message  = "";
        message = read(*(this->tcp_socket));  

        std::cout << message << std::endl;

        std::vector<std::string> info = this->decriptMessage(message);

        std::cout << info[0] << std::endl;
        std::cout << info[1] << std::endl;  

        this->vertified(info[0],info[1]);
    }
    
}


std::vector<std::string> server::decriptMessage(std::string str) 
{ 
   std::string word = ""; 
   std::vector<std::string> list;
   for (auto x : str) 
   { 

    if(x == '\n') {
        list.push_back(word);
    }else {
        if (x == ' ') { 
            //std::cout << word << std::endl;
            list.push_back(word);
            word = ""; 
        
        } else{ 
            word = word + x; 
        } 
    }
    

       
       
   }  
   //std::cout << word << std::endl;
   
   return list;
   
} 



bool server::vertified(std::string username, std::string pass) {
    
    DbManager db(path);
    QString loginID = QString::fromStdString(username);
    //std::cout << loginID.toUtf8().constData() << std::endl;
    QString password = QString::fromStdString(pass);
    if(db.loginAccount(loginID, password)) {
        std::cout << "Login Successfullly" << std::endl;
        return true;
        //QMessageBox::information(this, "Login", "Login Successful");
    }else{
        std::cout << "LoginID or Password is incorrect" << std::endl;
        return false;
    }
    
}

//TOFIX: Bug -> stack smashing 
std::string server::read(ip::tcp::socket & socket){
    streambuf buf;
    read_until(socket, buf, "\n");
    std::string data = buffer_cast<const char*>(buf.data());
    return data;
}




//TODO: