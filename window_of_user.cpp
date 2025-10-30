#include "window_of_user.h"
#include "./ui_window_of_user.h"
#include "./struct.h"

Window_of_User::Window_of_User(QWidget*object):
    QMainWindow(object),
    ui(new Ui::Window_of_User)
{
    ui->setupUi(this);
    init();
}

Window_of_User::~Window_of_User()
{
    delete ui;
}

void Window_of_User::init()
{
    //背景

    //头像，个签，名字
    setWindowTitle("🐧QQ");
    struct user_info* df = new struct user_info;
    ui->label_username->setText(df->user_name);
    QPixmap m_headphoto(df->user_headphoto_path);
    ui->label_headphoto->setPixmap(m_headphoto);
    ui->textEdit_personal_sign->setPlaceholderText("点击输入个性签名：");
    ui->textEdit_personal_sign->clear();
    m_user=new struct user_info;//从数据库根据账号获取user——info，赋给m_user
    if(m_user->user_sign != "")
    {
        ui->textEdit_personal_sign->setText(m_user->user_sign);
        //以及其他设置信息
    }
    if(m_user->user_name != "")
    {
        ui->label_username->setText(m_user->user_name);
    }
    if(m_user->user_headphoto_path != "")
    {
        QPixmap mphoto(m_user->user_headphoto_path);
        ui->label_headphoto->setPixmap(mphoto);
    }
    //按钮

}

//slots
void Window_of_User::SetPensonalSign()
{
    QString tempstr;
    tempstr=ui->textEdit_personal_sign->toPlainText();
    m_user->user_sign=tempstr;
    //更新到数据库？？
}

