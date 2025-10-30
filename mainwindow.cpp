#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include"m_editline_and_lable.h"
#include<QVBoxLayout>
#include<QTimer>
#include<window_of_user.h>
#include<QPixmap>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setInit();


    GetConfigWidget();
    SetConnect();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInit()
{
    setWindowTitle("HI LO !!");
    QPixmap headphoto(":/images/prefix1/qrc/image/im1.png");
    ui->label_headphoto->setPixmap(headphoto);
}
void MainWindow::GetConfigWidget()
{
    ui->Widget_id->SetPlaceHolder("请输入6位数字账号：");
    ui->Widget_id->SetLength(6);
    ui->Widget_id->SetFieldName("账号");
    ui->Widget_password->SetPlaceHolder("请输入8位密码：");
    ui->Widget_password->SetLength(8);
    ui->Widget_password->SetFieldName("密码");

}

void MainWindow::SetConnect()
{
    connect(ui->pushButton_login,&QPushButton::clicked,this,&::MainWindow::onLogin);
}

//slots
void MainWindow::onLogin()
{
    if(!FormatCheck())
    {
        const QString mytitle=windowTitle();
        setWindowTitle("登录失败，请检查输入后重试！");
        QTimer::singleShot(2000,this,[this,mytitle](){
            setWindowTitle(mytitle);
        });
        return;//go fail;
    }

    //jiancha  zhanghao mima xinxi

    this->close();
    QMainWindow* m_Window_User = new Window_of_User;
    m_Window_User->show();
}

//工具函数
bool MainWindow::FormatCheck()
{
    if(ui->Widget_id->Text().length() != ui->Widget_id->GetLength())
    {
        ui->Widget_id->SetFlag(false);
        return false;
    }
    if(ui->Widget_password->Text().length() != ui->Widget_password->GetLength())
    {
        ui->Widget_password->SetFlag(false);
        return false;
    }
    QString mystr=ui->Widget_id->Text();
    QChar mchar;
    for(int i=0;i<mystr.length();i++)
    {
        if(mystr[i]>'9' || mystr[i]<'0')
        {
            return false;
        }
    }
    return true;
}
