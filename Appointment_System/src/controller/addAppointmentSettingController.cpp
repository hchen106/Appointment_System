#include "controller.h"
#include "src/model/tcpConnection.h"
#include <iostream>



using namespace boost::asio;


Controller::addAppointmentSettingController::addAppointmentSettingController(tcpConnection::pointer new_connection_,std::string username) {
    new_connection = new_connection_;
    loginID = username;
}