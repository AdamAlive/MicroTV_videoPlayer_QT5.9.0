#ifndef MYSQL_H
#define MYSQL_H
#include <QObject>
class MySql:public QObject
{
public:
    MySql(QObject*parent = 0);

    void connDB();
    bool querryDB(const QString &sql);

    void checkMaxId();	//查询最大id
    void insert();		//插入数据
    void upDate();		//更新数据
    void checkName();	//查询部分数据(accountName)
    void cheakPassword();	//查询部分数据(password)
    void checkIdentity();	//查询部分数据(Identity)
    void allData();		//查询所有数据
    void deleteData();	//删除数据
    void clearDataBase();	//清空表
    //void closeDataBase();	//关闭数据库
    void deleteDataBase(); 	//删除数据库

private:
    //int id;
    QString dbDriver;
    QString dbName;
    QString dbuserName;
    QString dbpassword;
    QString hostName;
    int hostPort;
    int max_id;
    QString create_sql ;
    QString select_max_sql ;
    QString insert_sql ;
    QString update_sql ;
    QString select_name_sql ;
    QString select_password_sql ;
    QString select_Identity_sql ;
    QString select_all_sql ;
    QString delete_sql ;
    QString clear_sql ;
};
#endif
