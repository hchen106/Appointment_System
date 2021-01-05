#ifndef DBMANGER_H
#define DBMANGER_H
#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>

class DbManager {
public:
        DbManager(const QString& path);
        ~DbManager();

        bool signupAccount(const QString& name, const QString& loginID, const QString& password, int open_hour, int open_min, int close_hour, int close_min, const QString& gap_time);

        bool loginAccount(const QString& loginID, const QString& password);

        bool checkExist(const QString& loginID);

        bool addNewClient(const QString& name, const QString& birthday, const QString& email, const QString& provider, const QString& phone, const QString& address, const QString& providerID);

        QSqlQuery getClientList(QString& loginID);

        QString getClientInfo(QString& id);

        bool updateClientInfo(const QString& id, const QString& name, const QString& birthday, const QString& email, const QString& provider, const QString& phone, const QString& address);

        QString getTime(const QString& loginID);

        bool checkBooking(const QString& date, int hour, int min);

        bool addBooking(const QString& name, const QString& phone, const QString& email, const QString& date, const QString& hour, const QString min);

        bool checkExistClient(const QString& name, const QString& phone, const QString& email);

        bool updateTimeSetting(const QString& loginID, int open_hour, int open_min, int close_hour, int close_min, const QString& gap_time);


private:
        QSqlDatabase m_db;

};


#endif // DBMANGER_H
