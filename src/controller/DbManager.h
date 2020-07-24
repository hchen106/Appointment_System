#ifndef DBMANGER_H
#define DBMANGER_H
#include <QString>
#include <QSqlDatabase>

class DbManager {
public:
        DbManager(const QString& path);
        ~DbManager();

        bool signupAccount(const QString& name,const QString& loginID ,const QString& password);

        bool loginAccount(const QString& loginID, const QString& password);

        //static const QString path = "/home/huihao/Desktop/Login_test/Login/provider.db";

private:
        QSqlDatabase m_db;

};


#endif // DBMANGER_H
