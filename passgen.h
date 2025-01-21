#ifndef PASSGEN_H
#define PASSGEN_H
// #pragma once

#include <QWidget>
#include <qlabel.h>
#include <qpushbutton.h>
#include <QVBoxLayout>

class PassGen : public QWidget
{
Q_OBJECT
public:
    explicit PassGen(QWidget *parent = 0);
private:
    QPushButton button;
    QLabel label;
    int count;
    QVBoxLayout layout;
signals:
public slots:
private slots:
    void increaseCount();
};

#endif // WINDOW_H