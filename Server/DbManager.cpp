#include "DbManager.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>


DbManager::DbManager(const QString &path) {

    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open()) {
        qDebug() << "Error: connection fail";
    }else{
        qDebug() << "Database Connected";
    }

}

DbManager::~DbManager() {
    if(m_db.isOpen()) {
        m_db.close();
    }
}

bool DbManager::signupAccount(const QString& name, const QString& loginID, const QString& password, int open_hour, int open_min, int close_hour, int close_min, const QString& gap_time) {
    bool success = false;
    bool online_status = false;
    if(name == "" || loginID == "" || password == "" || abs(open_hour - close_hour) == 0) {
        return success;
    }
    QSqlQuery query;
    query.prepare("INSERT INTO provider (name, password, loginID, open_time_hour, open_time_min, close_time_hour, close_time_min, gap_time, online_status) VALUES (:name, :password, :loginID, :open_time_hour, :open_time_min, :close_time_hour, :close_time_min, :gap_time, :online_status)");
    qDebug() <<"prepare" << query.lastError();
    query.bindValue(":name", name);
    query.bindValue(":password", password);
    query.bindValue(":loginID", loginID);
    query.bindValue(":open_time_hour", open_hour);
    query.bindValue(":open_time_min", open_min);
    query.bindValue(":close_time_hour", close_hour);
    query.bindValue(":close_time_min", close_min);
    query.bindValue(":gap_time", gap_time);
    query.bindValue(":online_status", online_status);
    qDebug() <<"bind" << query.lastError();
    
    if(checkExist(loginID)) {
        if(query.exec()) {
            success = true;
        }else{
            qDebug() <<"fail to signup" << query.lastError();
        }
    }


    return success;
}

bool DbManager::loginAccount(const QString& loginID, const QString& password) {
    bool success = false;
    QSqlQuery query;
    query.prepare("SELECT loginID FROM PROVIDER WHERE loginID = (:loginID) AND password = (:password)");
    query.bindValue(":loginID", loginID);
    query.bindValue(":password", password);
    if(query.exec()) {
        qDebug() <<"exec" << query.lastError();
        if(query.next()) {
            success = true;
        }
    }
    qDebug() <<"fail to login" << query.lastError();
    return success;
}

bool DbManager::checkExist(const QString& loginID) {
    bool success = false;
    QSqlQuery query;
    query.prepare("SELECT loginID FROM provider WHERE loginID = (:loginID)");
    query.bindValue(":loginID", loginID);
    if(query.exec()) {
        if(!query.next()) {
            success = true;
        }
    }
    return success;
}

bool DbManager::addNewClient(const QString& name, const QString& birthday, const QString& email, const QString& provider, const QString& phone, const QString& address, const QString& providerID) {
    bool success = false;
    //QString providerid = "1997hao";
    QSqlQuery query;
    query.prepare("INSERT INTO client (name, birthday, email, address, provider, providerid, phone) VALUES (:name, :birthday, :email, :address, :provider, :providerid, :phone)");
    qDebug() <<"add prepare" << query.lastError();
    query.bindValue(":name", name);
    query.bindValue(":birthday", birthday);
    query.bindValue(":email", email);
    query.bindValue(":address", address);
    query.bindValue(":provider", provider);
    query.bindValue(":providerid", providerID);
    query.bindValue(":phone", phone);
    if(query.exec()) {
        success = true;
    }else{
        qDebug() <<"fail to add new client" << query.lastError();
    }
    return success;

}

bool DbManager::updateClientInfo(const QString& id, const QString& name, const QString& birthday, const QString& email, const QString& provider, const QString& phone, const QString& address) {
    bool success = false;
    QSqlQuery query;
    query.prepare("UPDATE client SET name = (:name), birthday = (:birthday), email = (:email), address = (:address), provider = (:provider), phone = (:phone) where id = (:id)"  );
    qDebug() <<"add prepare" << query.lastError();
    query.bindValue(":name", name);
    query.bindValue(":birthday", birthday);
    query.bindValue(":email", email);
    query.bindValue(":address", address);
    query.bindValue(":provider", provider);
    query.bindValue(":phone", phone);
    query.bindValue(":id", id);
    if(query.exec()) {
        success = true;
    }else{
        qDebug() <<"fail to update client" << query.lastError();
    }
    return success;
}

QSqlQuery DbManager::getClientList(QString& loginID) {
    QSqlQuery query;
    query.prepare("SELECT id, name, phone, email From client where providerid = (:providerid)");
    query.bindValue(":providerid", loginID);
    query.exec();
    return query;
}

QString DbManager::getClientInfo(QString& id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM client where id = (:id)");
    query.bindValue(":id", id);
    QString info = "";
    if(query.exec()) {
        while(query.next()) {
            info += query.value(1).toString() + "+" +
                query.value(2).toString() + "+" +
                query.value(3).toString() + "+" +
                query.value(4).toString() + "+" +
                query.value(5).toString() + "+" +
                query.value(6).toString() + "+" +
                query.value(7).toString() + "+" + 
                query.value(0).toString();
        }        
    }else {
        qDebug() << "Error: fail to get client info" << query.lastError();
    }

    return info;
}

QString DbManager::getTime(const QString& loginID) {
    QSqlQuery query;
    query.prepare("SELECT open_time_hour, open_time_min, close_time_hour, close_time_min, gap_time FROM provider where loginID = (:loginID)");
    query.bindValue(":loginID", loginID);
    QString timeinfo = "";
    if(query.exec()) {
        while(query.next()) {
            timeinfo += query.value(0).toString() + "+" +
                query.value(1).toString() + "+" + 
                query.value(2).toString() + "+" + 
                query.value(3).toString() + "+" + 
                query.value(4).toString();  
        }
    }else{
        qDebug() << "Error : fail to get time info" << query.lastError();
    }

    return timeinfo;
}

 bool DbManager::checkBooking(const QString& date, int hour, int min) {
     bool exist = false;
     QSqlQuery query;
     query.prepare("SELECT * FROM booking where date = (:date) and hour = (:hour) and min = (:min)");
     query.bindValue(":date", date);
     query.bindValue(":hour", hour);
     query.bindValue(":min", min);
     if(query.exec()) {
        if(!query.next()) {
            qDebug() << "false";
        }else{
            exist = true;
            qDebug() << "true";
        }
    }else{
        qDebug() << "checkbooking fail" << query.lastError();
    }
    return exist;

 }


bool DbManager::addBooking(const QString& name, const QString& phone, const QString& email, const QString& date, const QString& hour, const QString min) {
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO booking (name, phone, email, date, hour, min) VALUES (:name, :phone, :email, :date, :hour, :min)");
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);
    query.bindValue(":email", email);
    query.bindValue(":date", date);
    query.bindValue(":hour", hour);
    query.bindValue(":min", min);
    if(query.exec()) {
        success = true;
    }else{
        qDebug() << "Error: fail to add booking" <<query.lastError();
    }
    
    return success;


}

bool DbManager::checkExistClient(const QString& name, const QString& phone, const QString& email) {
    bool exist = false;
    QSqlQuery query;
    query.prepare("SELECT id from client where name = (:name) AND phone = (:phone) AND email = (:email)");
    query.bindValue(":name", name);
    query.bindValue(":phone", phone);
    query.bindValue(":email", email);
    if(query.exec()) {
        if(!query.next()) {
            qDebug() << "false";
        }else{
            exist = true;
            qDebug() << "true";
        }
    }else{
        qDebug() << "checkbooking fail" << query.lastError();
    }
    return exist;
}

 bool DbManager::updateTimeSetting(const QString& loginID, int open_hour, int open_min, int close_hour, int close_min, const QString& gap_time ) {
     bool success = false;
     QSqlQuery query;
     query.prepare("UPDATE provider SET open_time_hour = (:open_time_hour), open_time_min = (:open_time_min), close_time_hour = (:close_time_hour), close_time_min = (:close_time_min), gap_time = (:gap_time) where loginID = (:loginID)");
     query.bindValue(":loginID", loginID);
     query.bindValue(":open_time_hour", open_hour);
     query.bindValue(":open_time_min", open_min);
     query.bindValue(":close_time_hour", close_hour);
     query.bindValue(":close_time_min", close_min);
     query.bindValue(":gap_time", gap_time);
    if(query.exec()) {
        success = true;
    }else{
        qDebug() <<"fail to update setting" << query.lastError();
    }
    return success;
 }