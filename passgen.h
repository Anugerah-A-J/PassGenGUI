#ifndef PASSGEN_H
#define PASSGEN_H

#include <QWidget>
#include <QCheckBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>

class PassGen : public QWidget
{
Q_OBJECT
public:
    explicit PassGen(QWidget *parent = 0);
private:
    QCheckBox lowerCase;
    QCheckBox upperCase;
    QCheckBox number;
    QCheckBox symbol;
    QSpinBox passwordLength;
    QPushButton generate;
    QLabel password;
    int count;
    QGridLayout layout;
signals:
public slots:
private slots:
    void increaseCount();
};

#endif // WINDOW_H