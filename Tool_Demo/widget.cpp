#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    resize(800,600);

    QVBoxLayout* layout_top = new QVBoxLayout(this);
    QVBoxLayout* v_layout = new QVBoxLayout();
    message_info = new QTextBrowser();
//    message_info->setGeometry(20,20,600,400);

    send_box = new QTextEdit();
    send_box->setMaximumHeight(150);

    btn_clear = new QPushButton();
    btn_clear->setText("清理信息显示区");

    is_clear = new QCheckBox();
    is_clear->setText("清理发送区信息");

    btn_send = new QPushButton();
    btn_send->setText("发送");
    QHBoxLayout* h_layout = new QHBoxLayout();
    h_layout->addWidget(btn_clear);
    h_layout->addWidget(is_clear);
    h_layout->addWidget(btn_send);

    v_layout->addWidget(message_info);
    v_layout->addWidget(send_box);
    v_layout->addLayout(h_layout);
    layout_top->addLayout(v_layout);
}

void Widget::build_connect()
{
    connect(btn_clear,SIGNAL(clicked(bool)),this,SLOT(clear_message_info()));
    connect(btn_send,SIGNAL(clicked(bool)),this,SLOT(send_message(const char*)));
}

Widget::~Widget()
{

}

void Widget::send_message(const char* str)
{

}

void Widget::clear_message_info()
{

}

