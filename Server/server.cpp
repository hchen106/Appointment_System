#include "server.h"


//static const QString path = "/home/matthew779/appointment_system/Appointment_System/Server/provider.db";
static const QString path = "/Users/xinhaoxiao/Desktop/document/Appointment_System/Server/provider.db";

using namespace server;

tcp_server::tcp_server(boost::asio::io_service& io_service): 
    io_service_(io_service), acceptor_(io_service, ip::tcp::endpoint(ip::tcp::v4(), 8003)),context_(boost::asio::ssl::context::sslv23) {
    stop = true;
    context_.set_options(
        boost::asio::ssl::context::default_workarounds
        | boost::asio::ssl::context::no_sslv2
        | boost::asio::ssl::context::single_dh_use);
    context_.set_password_callback(std::bind(&tcp_server::get_password, this));
    context_.use_certificate_chain_file("rootca.crt");
    context_.use_private_key_file("rootca.key", boost::asio::ssl::context::pem);
    context_.use_tmp_dh_file("dh2048.pem");
    start_accept();
    std::cout << "Server End" << std::endl;
}

std::string tcp_server::get_password() const{
    return "test";
}

void tcp_server::start_accept() {

    //add SSL security context
    

    tcp_connection::pointer new_connection = tcp_connection::create(io_service_,context_);
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

tcp_connection::pointer tcp_connection::create(boost::asio::io_service& io_service, boost::asio::ssl::context& context_) {

    return tcp_connection::pointer(new tcp_connection(io_service,context_));
}

ip::tcp::socket& tcp_connection::socket() {
    return socket_;
}

void tcp_connection::wait_for_response(server::tcp_connection::pointer new_connection) {

    //Send a sample message back to clients when they first connected to server. 

    

    //boost::asio::async_write(socket_, boost::asio::buffer("Hello"), 
    //    boost::bind(&tcp_connection::handle_write, shared_from_this()));
    

    
    //socket_list.push_back(("1",new_connection->socket()));
    
    std::cout << "Sent" << std::endl;
    boost::system::error_code error;
    boost::array<char, 128> buffer;
    buf;
    std::cout << buf.data() << std::endl;
    //size_t len = new_connection->socket().read_some(boost::asio::buffer(buf));
    new_connection->socket().async_read_some(boost::asio::buffer(buf),boost::bind(&tcp_connection::handle_read,shared_from_this()
        ,new_connection,boost::asio::placeholders::bytes_transferred));
    //boost::asio::async_write(new_connection->socket(), boost::asio::buffer("Approved"), 
    //    boost::bind(&tcp_connection::handler, shared_from_this()));
    
    
}

void tcp_connection::handler(server::tcp_connection::pointer new_connection) {
    std::cout << "handler" << std::endl;
    wait_for_response(new_connection);
}

void tcp_connection::handle_read(server::tcp_connection::pointer new_connection,size_t bytes_transferred) {

    //std::cout << buffer.data() << std::endl;
    message_command mes;
    //std::cout << bytes_transferred << std::endl;
    //std::istream is(&buf);
    //std::string s =buf.c_array();
    std::string str = buf.data();
    str = str.substr(0,bytes_transferred);
    std::vector<std::string> list = mes.decode(str);
    //std::cout << mes.get_User() << " " << mes.get_Command() << std::endl;
    std::cout << "start" << std::endl;
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
                boost::bind(&tcp_connection::handler, shared_from_this(),new_connection));
            //QMessageBox::information(this, "Login", "Login Successful");
        }else{
            boost::asio::async_write(new_connection->socket(), boost::asio::buffer("Failed"), 
                boost::bind(&tcp_connection::handler, shared_from_this(), new_connection));
            std::cout << "LoginID or Password is incorrect" << std::endl;
            
        }
            
    }
    //std::cout << "done" << std::endl;

    if(mes.get_Command() == "logout") {
        std::cout << "Logout" << std::endl;
        new_connection->socket().close();
    }


    if(mes.get_Command() == "addClient") {
        std::cout << "addClient stage" << std::endl;
        boost::array<char, 512> buf;
        std::size_t len = boost::asio::read(new_connection->socket(),boost::asio::buffer(buf));
        std::cout << buf.data() << std::endl;

        Json::Value jsonPacket;
        std::stringstream(buf.data()) >> jsonPacket;
        std::cout << jsonPacket << std::endl;
        QString name = QString::fromStdString(jsonPacket["name"].asString());
        QString birthday = QString::fromStdString(jsonPacket["birthday"].asString());
        QString email = QString::fromStdString(jsonPacket["email"].asString());
        QString provider = QString::fromStdString(jsonPacket["provider"].asString());
        QString phone = QString::fromStdString(jsonPacket["phone"].asString());
        QString address = QString::fromStdString(jsonPacket["address"].asString());
        QString providerID = QString::fromStdString(jsonPacket["providerid"].asString());


        DbManager db(path);
        if(db.addNewClient(name, birthday, email, provider, phone, address, providerID)){
            std::cout << "Client is Successfully added" << std::endl;
        }else{
            std::cout << "Client is fail to add"  << std::endl;
        }
        tcp_connection::handler(new_connection);
        
    }

    if(mes.get_Command() == "loadall") {
        
        DbManager db(path);
        QSqlQuery qry;
        QString loginID = QString::fromStdString(mes.get_User());
        std::cout << "loadAll" << std::endl;
        std::cout << mes.get_User() << std::endl;
        //qDebug() << loginID;
        qry = db.getClientList(loginID);
        std::cout << "Got query result......." <<std::endl; 
        while(qry.next()) {
            std::string id = qry.value(0).toString().toUtf8().constData();
            std::string name = qry.value(1).toString().toUtf8().constData();
            std::string phone = qry.value(2).toString().toUtf8().constData();
            std::string email = qry.value(3).toString().toUtf8().constData();
            std::string address = qry.value("address").toString().toUtf8().constData();

            std::cout << "address: " << address << std::endl; 
            //std::cout << id + " " + name + " "  + email  + " " + phone << std::endl;
            Json::Value jsonPacket;
            jsonPacket["id"] = id;
            jsonPacket["name"] = name;
            jsonPacket["email"] = email;
            jsonPacket["phone"] = phone;
            jsonPacket["address"] = address;


            //std::cout << jsonPacket << std::endl;
            //std::cout << jsonPacket << std::endl;
            //Json::StreamWriterBuilder fastWriter;
            Json::FastWriter fastWriter;
            //std::cout << fastWriter.write(jsonPacket) << std::endl;
            
            std::string str = fastWriter.write(jsonPacket); 
            Json::Value j;
            std::stringstream(str) >> j;
            //std::cout << j << std::endl;
            //boost::asio::async_write(new_connection->socket(), boost::asio::buffer(str), 
            //    boost::bind(&tcp_connection::temp_handler, shared_from_this()));
            boost::array<char, 128> buf;
            buf.data() == str;
            //boost::asio::write(new_connection->socket(), boost::asio::buffer(str));
            send_message(new_connection,str);
            //std::size_t len = boost::asio::read(new_connection->socket(),boost::asio::buffer(buf));
            
        }
        //boost::asio::async_write(new_connection->socket(), boost::asio::buffer("End"), 
        //        boost::bind(&tcp_connection::handler, shared_from_this(), new_connection));
        send_message(new_connection,"End");
        //boost::asio::write(new_connection->socket(), boost::asio::buffer("End"));
        tcp_connection::handler(new_connection);
        std::cout << "done" << std::endl;
    }
    
    
}

void tcp_connection::send_message(tcp_connection::pointer new_connection, std::string str) {
    
    boost::array<char, 512> buf;
    //buf =  str;
    std::cout << str.size() << std::endl;
    if(str.size() < 512) {
        std::string extension(512-str.size(), ' ');
        str = str + extension;
    }
    boost::asio::write(new_connection->socket(), boost::asio::buffer(str,512));
    // while(buf.data() != "received") {
    //     std::size_t len = boost::asio::read(new_connection->socket(),boost::asio::buffer(buf));
    // }
    
    
    
}

void tcp_connection::temp_handler() {

}

void tcp_connection::vertify(boost::array<char,128> buff) {

    std::cout << buff.data() << std::endl;
    
    
}

tcp_connection::tcp_connection(boost::asio::io_service& io_service, boost::asio::ssl::context& context) : socket_(io_service), tcp_socket(std::move(socket_),context) {

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
    int pos =  command.find(' ');
    command = command.substr(0,pos);
    std::cout << "command: " << command << std::endl;
    return  command;
}

