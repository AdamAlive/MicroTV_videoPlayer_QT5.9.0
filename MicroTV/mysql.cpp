#include <QtSql>

#include <QSqlDatabase>

#include <QDebug>

#include "mysql.h"

#include <QMainWindow>

#include <string>

#include <QApplication>

MySql::MySql(QObject*parent)

:QObject(parent)

{

    dbDriver="QUserSql";

    dbName="Users.db";

    dbuserName="dalao";

    dbpassword="admins";

    hostName="localhost";

    hostPort=54321;

    connDB();//int the constructor to construct a sql

}


void MySql::connDB()
{
    //int argc;
    //char *argv[25];
    //QApplication a(argc, argv);
        QMainWindow w;

        qDebug() << QSqlDatabase::drivers();

    QSqlDatabase db = QSqlDatabase::addDatabase(dbDriver);//添加驱动

    db.setHostName(hostName);//设置主机名

    db.setDatabaseName(dbName);//设置数据库名

    db.setUserName(dbuserName);//设置用户名

    db.setPassword(dbpassword);//设置用户密码
    //Above all are all be set to initialize an sql

    //打开数据库
        if(!db.open())
        {
            qDebug()<<db.lastError();
            w.setWindowTitle("failed to connect.") ;
            w.show();
        //return false;
        }
        else
        {
        //return true;
    //QSqlQuery类提供执行和操作的SQL语句的方法。
        //可以用来执行DML（数据操作语言）语句，如SELECT、INSERT、UPDATE、DELETE，
        //以及DDL（数据定义语言）语句，例如CREATE TABLE。
        //也可以用来执行那些不是标准的SQL的数据库特定的命令。
        QSqlQuery sql_query;

        QString create_sql = "create table account (id int primary key, name 	varchar(12), password varchar(20),vipFlag bit,Identity int)";
        select_max_sql = "select max(id) from account";
        insert_sql = "insert into account values (?, ?, ?, ?, ?)";
        update_sql = "update account set name = :name where id = :id";
        select_name_sql = "select id, name from account";
        select_password_sql = "select id, password from account";
        select_Identity_sql = "select id, Identity from account";
        select_all_sql = "select * from account";
        delete_sql = "delete from account where id = ?";
        clear_sql = "delete from account";
    //really costruct a sql
    //return true;
    sql_query.prepare(create_sql);
        if(!sql_query.exec())
        {
        qDebug()<<db.lastError();
        w.setWindowTitle("error happened!");
        w.show();
        }
        else
        {
        w.setWindowTitle("table created!");
        w.show();
        }
    }
}

//inthis case, we can just think that we haved diviede the constructure of the sql into two functions

void MySql::checkMaxId()
{
    QSqlQuery sql_query;

    int max_id = 0;
        sql_query.prepare(select_max_sql);
        if(!sql_query.exec())
        {
            qDebug()<<sql_query.lastError();
        }
        else
        {
            while(sql_query.next())
            {
                max_id = sql_query.value(0).toInt();
                qDebug()<<QString("max id:%1").arg(max_id);
            }
        }
}

void MySql::insert()		//插入数据
{
    QSqlQuery sql_query;
    sql_query.prepare(insert_sql);
    sql_query.addBindValue(max_id+1);
    sql_query.addBindValue("name");
    sql_query.addBindValue(25);           //?????????????????
    if(!sql_query.exec())
    {
    qDebug()<<sql_query.lastError();
    }
    else
    {
    qDebug()<<"inserted!";
    }
}

void MySql::upDate()		//更新数据
{
    QSqlQuery sql_query;
    sql_query.prepare(update_sql);
    sql_query.bindValue(":name", "Qt");
    sql_query.bindValue(":id", 1);
    if(!sql_query.exec())
    {
    qDebug()<<sql_query.lastError();
    }
    else
    {
    qDebug()<<"updated!";
    }
}

void MySql::checkName()	//查询部分数据(accountName)
{
    QSqlQuery sql_query;
    if(!sql_query.exec(select_name_sql))
    {
    qDebug()<<sql_query.lastError();
    }
    else
    {
    while(sql_query.next())
    {
    int id = sql_query.value("id").toInt();
    QString name = sql_query.value("name").toString();

    qDebug()<<QString("id:%1    name:%2").arg(id).arg(name);
    }
    }
}

void MySql::cheakPassword()	//查询部分数据(password)
{
    QSqlQuery sql_query;
    if(!sql_query.exec(select_name_sql))
    {
    qDebug()<<sql_query.lastError();
    }
    else
    {
    while(sql_query.next())
    {
    int id = sql_query.value("id").toInt();
    QString password = sql_query.value("password").toString();

    qDebug()<<QString("id:%1    password:%3").arg(id).arg(password);
    }
    }
}
void MySql::checkIdentity()	//查询部分数据(Identity)
{
    QSqlQuery sql_query;
if(!sql_query.exec(select_name_sql))
    {
    qDebug()<<sql_query.lastError();
    }
    else
    {
    while(sql_query.next())
    {
    int id = sql_query.value("id").toInt();
    int Identity = sql_query.value("Identity").toInt();

    qDebug()<<QString("id:%1    Identity:%5").arg(id).arg(Identity);
    }
    }
}

void MySql::allData()		//查询所有数据
{
    QSqlQuery sql_query;
    sql_query.prepare(select_all_sql);
    if(!sql_query.exec())
    {
    qDebug()<<sql_query.lastError();
    }
    else
    {
    while(sql_query.next())
    {
    int id = sql_query.value(0).toInt();
    QString name = sql_query.value(1).toString();
    QString password = sql_query.value(2).toString();
    int Identity = sql_query.value(4).toInt();

    qDebug()<<QString("id:%1    name:%2    password:%3    Identity%5").arg(id).arg(name).arg(password).arg(Identity);
    }
}
    }

void MySql::deleteData()	//删除数据
{
    QSqlQuery sql_query;
    sql_query.prepare(delete_sql);
    sql_query.addBindValue(max_id);
    if(!sql_query.exec())
    {
    qDebug()<<sql_query.lastError();
    }
    else
    {
    qDebug()<<"deleted!";
    }
}

void MySql::clearDataBase()	//清空表
{
    QSqlQuery sql_query;
    sql_query.prepare(clear_sql);
    if(!sql_query.exec())
    {
    qDebug()<<sql_query.lastError();
    }
    else
    {
    qDebug()<<"cleared";
    }

}


/*void MySql::deleteDataBase()
{
    QFile::remove();
}*/
