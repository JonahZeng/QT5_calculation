#include "calc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PlusMinus window;

    window.resize(300, 500);
    window.setWindowTitle("calc");
    window.show();

    return a.exec();
}
