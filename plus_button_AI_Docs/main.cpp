#include <QApplication>
#include "plus_button.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    plus_button obj(nullptr);
    obj.show();
    return a.exec();
}
