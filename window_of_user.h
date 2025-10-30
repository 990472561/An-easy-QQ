#ifndef WINDOW_OF_USER_H
#define WINDOW_OF_USER_H

#include <QMainWindow>
#include "./struct.h"

QT_BEGIN_NAMESPACE
namespace Ui {
    class Window_of_User;
}
QT_END_NAMESPACE

class Window_of_User:public QMainWindow
{
    Q_OBJECT
public:
    Window_of_User(QWidget* object= nullptr);
    ~Window_of_User();


public: // fuc
    void init();

public slots:
    void SetPensonalSign();

private:
    Ui::Window_of_User* ui;
    struct user_info* m_user;
};



#endif // WINDOW_OF_USER_H
