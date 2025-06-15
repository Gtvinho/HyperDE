#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include "Waybar/WaybarConfig.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("HyprDE Launcher");

    QPushButton *waybarButton = new QPushButton("Abrir Configurador Waybar");

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(waybarButton);

    QObject::connect(waybarButton, &QPushButton::clicked, [&]() {
        WaybarConfig *editor = new WaybarConfig();
        editor->setAttribute(Qt::WA_DeleteOnClose);
        editor->show();
    });

    window.show();
    return app.exec();
}

