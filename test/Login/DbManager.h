#ifndef DBMANGER_H
#define DBMANGER_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

class DbManager {
public:
        DbManager(const QString& path);
        ~DbManager();

        bool signupAccount(const QString& name,const QString& loginID ,const QString& password);

        bool loginAccount(const QString& loginID, const QString& password);

        bool checkExist(const QString& loginID);

        bool addNewClient(const QString& name, const QString& birthday, const QString& email, const QString& provider, const QString& phone, const QString& address, const QString& providerID);

        QSqlQuery getClientList(QString& loginID);

        QString getClientInfo(QString& name);

        bool updateClientInfo(const QString& id, const QString& name, const QString& birthday, const QString& email, const QString& provider, const QString& phone, const QString& address);


private:
        QSqlDatabase m_db;

};


#endif // DBMANGER_H
