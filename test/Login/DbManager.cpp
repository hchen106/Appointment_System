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

bool DbManager::signupAccount(const QString& name, const QString& loginID, const QString& password) {
    bool success = false;
    QSqlQuery query;
    query.prepare("INSERT INTO provider (name, password, loginID) VALUES (:name, :password, :loginID)");
    qDebug() <<"prepare" << query.lastError();
    query.bindValue(":name", name);
    query.bindValue(":password", password);
    query.bindValue(":loginID", loginID);
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

bool DbManager::addNewClient(const QString& name, const QString& birthday, const QString& email, const QString& provider, const QString phone, const QString& address, const QString& providerID) {
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

  QSqlQuery DbManager::getClientList(QString& loginID) {
      QSqlQuery query;
      query.prepare("SELECT name From client where providerid = (:providerid)");
      query.bindValue(":providerid", loginID);
      query.exec();
      return query;
  }