#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QLayout>
#include <QTextBrowser>
#include <QCheckBox>
#include <QLabel>
#include <string>

using namespace std;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

    void build_connect();

public slots:
    void send_message(const char* str);
    void clear_message_info();

private:
    QTextBrowser* message_info;
    QTextEdit* send_box;

    QPushButton* btn_send;
    QPushButton* btn_clear;

    QCheckBox* is_clear;



};

#endif // WIDGET_H
