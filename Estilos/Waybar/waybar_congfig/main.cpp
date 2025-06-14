#include <QApplication>
#include "WaybarConfig.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    WaybarConfig window;
    window.show();
    return app.exec();
}

