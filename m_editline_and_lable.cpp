#include "m_editline_and_lable.h"
#include <qlabel.h>
#include <qlineedit.h>
#include <QHBoxLayout>

m_editline_and_lable::m_editline_and_lable(QWidget*parent):
    QWidget(parent)
{
    m_lineedit=new QLineEdit;
    m_lineedit->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Preferred);
    m_label=new QLabel("");
    m_label->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Preferred);
    QHBoxLayout* layout=new QHBoxLayout(this);
    layout->addWidget(m_lineedit);
    layout->addWidget(m_label);

    setLayout(layout);

    connect(m_lineedit,&QLineEdit::textEdited,this,&m_editline_and_lable::on_TextEdit);
}

m_editline_and_lable::m_editline_and_lable(const QString& m_placeholder,const QString& fieldname,
                                           int length,QWidget*parent):
    m_editline_and_lable(parent)
{
    m_length=length;
    m_fieldname=fieldname;
    m_lineedit->setPlaceholderText(m_placeholder);
}

//
QString m_editline_and_lable::Text()const
{
    return m_lineedit->text();
}

void m_editline_and_lable::SetPlaceHolder(const QString& text)
{
    m_lineedit->setPlaceholderText(text);
}

void m_editline_and_lable::SetLength(int num)
{
    m_length=num;
}

int m_editline_and_lable::GetLength()
{
    return m_length;
}

void m_editline_and_lable::SetFieldName(const QString& text)
{
    m_fieldname=text;
}

//slots
void m_editline_and_lable::on_TextEdit()
{
    QString m_num_in =Text();
    m_lineedit->setStyleSheet("");
    if(m_num_in.length()<m_length)
    {
        m_label->setText(QString("❌ %1还差%2位").arg(m_fieldname).arg(m_length-m_num_in.length()));
        m_label->setStyleSheet("color: orange");
    }
    else if(m_num_in.length()==m_length)
    {
        m_label->setText(QString("✔ 格式正确"));
        m_label->setStyleSheet("color: green");
    }
    else
    {
        m_label->setText(QString("❌ %1超出%2位").arg(m_fieldname).arg(m_num_in.length()-m_length));
        m_label->setStyleSheet("color: red");
    }
    m_label->adjustSize();
}

void m_editline_and_lable::SetFlag(bool result)
{
    if(!result)
    {
        m_lineedit->setStyleSheet("border:2px solid red");
    }
}
