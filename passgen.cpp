#include "passgen.h"

PassGen::PassGen(QWidget *parent):
    QWidget{parent},
    lowerCase{"a-z", this},
    upperCase{"A-Z", this},
    number{"0-9", this},
    symbol{"!@#$%^&*()", this},
    passwordLength{this},
    generate{"Generate", this},
    password{this},
    count{0},
    layout{this}
{
    layout.addWidget(&lowerCase, 0, 0);layout.addWidget(&upperCase, 0, 1);
    layout.addWidget(&number, 1, 0);layout.addWidget(&symbol, 1, 1);
    layout.addWidget(&passwordLength, 2, 0);layout.addWidget(&generate, 2, 1);
    layout.addWidget(&password, 3, 0, 1, 2);

    lowerCase.setCheckState(Qt::Checked);
    upperCase.setCheckState(Qt::Checked);
    number.setCheckState(Qt::Checked);
    symbol.setCheckState(Qt::Checked);
    number.setMinimumWidth(symbol.width());
    passwordLength.setMinimum(9);
    passwordLength.setMaximum(99);
    generate.setMinimumWidth(passwordLength.width());
    password.setAlignment(Qt::AlignCenter);

    connect(&generate, &QPushButton::clicked, this, &PassGen::increaseCount);
}

void PassGen::increaseCount()
{
    count++;
    password.setNum(count);
}