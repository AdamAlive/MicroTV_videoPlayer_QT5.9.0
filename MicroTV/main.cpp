#include "homewindow.h"
#include "rollcaption.h"
#include "account.h"
#include "User.h"
#include "tv_view.h"
#include "Administrator.h"
#include <QApplication>
#include <QWidget>
#include <string>
#include <QDebug>
#include <QtSql>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<User>lst;

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath("./plugins");

    string name1 = "admin";
    string passport1 = "admins";
    long int id1 = 88888888;
    bool vip1 = true;



    User user1;
    user1.setName(name1);
    user1.setpassport(passport1);
    user1.setID(id1);
    user1.setVip(vip1);
    qDebug() << QString::fromStdString(user1.getpassport());

    QApplication a(argc, argv);
    HomeWindow w;
    w.setWindowTitle(QObject::tr("Micro-TV"));
    w.accounttemp = user1.getName();
    w.passwordtemp = user1.getpassport();



    QWidget *l = new QWidget();

    l->setWindowTitle(QObject::tr("Title"));
    l->resize(320,45);
    //l->move(250,250);
    //l->show();
    //l->setGeometry(QRect(300,300,301,20));
    l->setObjectName(QString::fromUtf8("Title num2"));




    QString title = "Big Bang";
    bool free = true;
    Film film1(title.toStdString(),&user1,free );

    /*ofstream outUsers( "Users.txt", ios::out );
    if(!outUsers)
    {
        qDebug() << "can't open the file.";
    }

    //MySql mysql;


    outUsers  << user1.getName() << "@" << user1.getpassport() << "@" << user1.getID() << "@" << (user1.is_Vip()? "T":"F")<< "@"  ;
*/

            //读取账户的代码↓
            std::ifstream ifile("Users.txt",std::ios::in);
                if(!ifile)
                {
                    //qDebug()<<"Open file failed!";
                }
                char ch;
                int i;
                for (i=0;i<100;i++)//读取数目
                {
                    std::string s_name,s_id,s_passpord;
                    bool flag;
                    int count = 0;
                    if(!ifile.get(ch))
                    {
                         //qDebug()<<"文件已读取完毕！";
                         break;
                    }
                    while (ch!='@'&&(count%4!=0||count==0))//读取姓名
                    {
                        s_name+=ch;
                        ifile.get(ch);
                    }
                    count++;
                    ifile.get(ch);
                    while (ch!='@'&&(count%4!=0||count==0))//读取密码
                    {
                        s_passpord+=ch;
                        ifile.get(ch);

                    }
                    count++;
                    //qDebug()<<count;
                    ifile.get(ch);
                    while(ch!='@'&&(count%4!=0||count==0))//读取ID
                    {
                         s_id+=ch;
                         ifile.get(ch);
                    }
                    count++;
                    //qDebug()<<count;
                    //qDebug()<<ch;

                    while(ch=='@'&&count==3)//读取身份
                    {
                        //qDebug()<<"OK";

                         ifile.get(ch);
                         count++;
                         if(ch == '0')
                         {
                            flag=false;
                         }
                         else
                         {
                            flag=true;
                         }
                         //qDebug()<<flag;
                         if(!ifile.get(ch))
                         {
                             //qDebug()<<"File has been loaded.";
                             break;//continue;
                         }
                    }

                 User temp;

                    temp.setName(s_name);
                    QString temp1 = QString::fromStdString(s_id);
                    bool OK;
                    long int id = temp1.toInt(&OK,10);
                    temp.setID(id);
                    temp.setpassport(s_passpord);
                    temp.setVip(flag);
                    //qDebug()<< QString::fromStdString(temp.getName());

                    w.users[i].setName(s_name);
                    w.users[i].setpassport(s_passpord);
                    w.users[i].setID(id);
                    w.users[i].setVip(flag);
                    w.userSize++;
              }

            w.show();
    return a.exec();
}
