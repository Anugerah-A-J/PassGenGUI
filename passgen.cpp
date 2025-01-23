#include "passgen.h"
#include <algorithm>
#include <random>

PassGen::PassGen(QWidget *parent):
    QWidget{parent},
    lowerCaseCheckBox{"a-z", this},
    upperCaseCheckBox{"A-Z", this},
    numberCheckBox{"0-9", this},
    symbolCheckBox{"!@#$%^&*()", this},
    passwordLengthSpinBox{this},
    generate{"Generate", this},
    passwordLabel{this},
    layout{this},
    lowerCase{"qwertyuiopasdfghjklzxcvbnm"},
    upperCase{"QWERTYUIOPASDFGHJKLZXCVBNM"},
    number{"1234567890"},
    symbol{"!@#$%^&*()"},
    passwordLength{0},
    password{},
    rd{},
    shuffled{}
{
    shuffled.reserve(lowerCase.size() + upperCase.size() + number.size() + symbol.size());

    layout.addWidget(&lowerCaseCheckBox, 0, 0);layout.addWidget(&upperCaseCheckBox, 0, 1);
    layout.addWidget(&numberCheckBox, 1, 0);layout.addWidget(&symbolCheckBox, 1, 1);
    layout.addWidget(&passwordLengthSpinBox, 2, 0);layout.addWidget(&generate, 2, 1);
    layout.addWidget(&passwordLabel, 3, 0, 1, 2);

    lowerCaseCheckBox.setCheckState(Qt::Checked);
    upperCaseCheckBox.setCheckState(Qt::Checked);
    numberCheckBox.setCheckState(Qt::Checked);
    symbolCheckBox.setCheckState(Qt::Checked);
    numberCheckBox.setMinimumWidth(symbolCheckBox.width());
    passwordLengthSpinBox.setMinimum(9);
    passwordLengthSpinBox.setMaximum(99);
    password.reserve(99);
    generate.setMinimumWidth(passwordLengthSpinBox.width());
    passwordLabel.setAlignment(Qt::AlignCenter);

    connect(&generate, &QPushButton::clicked, this, &PassGen::generatePassword());
}

void PassGen::generatePassword()
{
    passwordLength = passwordLengthSpinBox.value();
    shuffled.clear();
    password.clear();

    if (lowerCaseCheckBox.checkState() == Qt::Checked)
        shuffled += lowerCase;

    if (upperCaseCheckBox.checkState() == Qt::Checked)
        shuffled += upperCase;

    if (numberCheckBox.checkState() == Qt::Checked)
        shuffled += number;

    if (symbolCheckBox.checkState() == Qt::Checked)
        shuffled += symbol;

    std::shuffle(shuffled.begin(), shuffled.end(), rd);

    std::uniform_int_distribution<> dist{0, static_cast<int>(shuffled.size())};

    for (int i = 0; i < passwordLength; ++i)
        password.push_back(shuffled.at(dist(rd)));

    passwordLabel.setText(password);
}