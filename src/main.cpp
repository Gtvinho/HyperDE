#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QMessageBox>

#include "WaybarConfig/WaybarConfig.h"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    QWidget window;
    window.setWindowTitle("HyprDE Launcher");

    QPushButton *waybarButton = new QPushButton("Abrir Configurador Waybar");
    QPushButton *hyprlandButton = new QPushButton("Abrir Configurador Hyprland");

    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(hyprlandButton);
    layout->addWidget(waybarButton);

    // Conexão do botão Waybar
    QObject::connect(waybarButton, &QPushButton::clicked, [&]() {
        WaybarConfig *editor = new WaybarConfig();
        editor->setAttribute(Qt::WA_DeleteOnClose);
        editor->show();
    });

    // Conexão do botão Hyprland
    QObject::connect(hyprlandButton, &QPushButton::clicked, [&]() {
        QMessageBox::information(nullptr, "Hyprland", "Futuramente aqui será o configurador do Hyprland!");
    });

    window.show();
    return app.exec();
}

