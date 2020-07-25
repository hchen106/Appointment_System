#include "controller/DbManager.h"
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

