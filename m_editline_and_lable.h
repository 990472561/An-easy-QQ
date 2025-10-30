#ifndef M_EDITLINE_AND_LABLE_H
#define M_EDITLINE_AND_LABLE_H

#include <QWidget>
#include<QString>

class QLabel;
class QLineEdit;

class m_editline_and_lable : public QWidget
{
    Q_OBJECT
public:
    //构造函数
    explicit m_editline_and_lable(QWidget*parent);
    explicit m_editline_and_lable(const QString& m_placeholder,const QString& fieldname,
                                               int length,QWidget*parent);


signals:
    void TextEdited(const QString& text);

public slots:
    void on_TextEdit();



public:
    //Text
    QString Text() const;
    //
    void SetPlaceHolder(const QString& text);
    //
    void SetLength(int num);
    int GetLength();
    //
    void SetFieldName(const QString& text);
    //
    void SetFlag(bool result);
private:
    QLineEdit* m_lineedit;
    QLabel* m_label;
    int m_length=0;
    QString m_fieldname="";
};

#endif // M_EDITLINE_AND_LABLE_H
