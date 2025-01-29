#ifndef PASSGEN_H
#define PASSGEN_H

#include <QWidget>
#include <QGroupBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <qgridlayout.h>
#include <qlabel.h>
#include <random>

class PassGen : public QWidget
{
Q_OBJECT
public:
    explicit PassGen(QWidget *parent = 0);
private:
    QGroupBox checkBoxGroupBox;
    QGridLayout checkBoxLayout;
    QCheckBox lowerCaseCheckBox;
    QCheckBox upperCaseCheckBox;
    QCheckBox numberCheckBox;
    QCheckBox symbolCheckBox;
    QLabel passwordLengthLabel;
    QSpinBox passwordLengthSpinBox;
    QPushButton generate;
    QLabel passwordLabel;
    QGridLayout layout;
    const std::string lowerCase;
    const std::string upperCase;
    const std::string number;
    const std::string symbol;
    std::random_device rd;
signals:
public slots:
private slots:
    void generatePassword();
};

#endif // PASSGEN_H