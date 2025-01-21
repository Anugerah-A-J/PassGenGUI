#include "passgen.h"

PassGen::PassGen(QWidget *parent):
    QWidget(parent),
    button("Hello World", this),
    label(this),
    count(0),
    layout(this)
{
    layout.addWidget(&button);
    layout.addWidget(&label);
    connect(&button, &QPushButton::clicked, this, &PassGen::increaseCount);
}

void PassGen::increaseCount()
{
    count++;
    label.setNum(count);
}