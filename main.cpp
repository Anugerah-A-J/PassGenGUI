#include <QApplication>
#include <QStyleHints>

#include "passgen.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    app.styleHints()->setColorScheme(Qt::ColorScheme::Dark);

    PassGen passGen;
    passGen.show();
    
    return QCoreApplication::exec();
}