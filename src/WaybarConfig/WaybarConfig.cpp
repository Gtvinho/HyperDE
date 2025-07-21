#include "WaybarConfig.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QCoreApplication>
#include <QDebug>

WaybarConfig::WaybarConfig(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("HyprDE - Waybar Config");

    // Criação dos checkboxes
    switchSom = new QCheckBox("Som", this);
    switchCPU = new QCheckBox("CPU", this);

    // Aplicar estilo QSS (opcional)
    QString stylePath = QCoreApplication::applicationDirPath() + "/../Styles/StylesCode/StyleCheckBox.qss";
    QFile styleFile(stylePath);
    if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&styleFile);
        QString style = in.readAll();
        switchSom->setStyleSheet(style);
        switchCPU->setStyleSheet(style);
        styleFile.close();
    } else {
        qWarning() << "❌ Não foi possível carregar o estilo:" << stylePath;
    }

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(switchSom);
    layout->addWidget(switchCPU);

    // Botão salvar
    saveButton = new QPushButton("Salvar Configuração", this);
    layout->addWidget(saveButton);
    setLayout(layout);

    // Conectar botão ao slot
    connect(saveButton, &QPushButton::clicked, this, &WaybarConfig::saveConfig);

    // 🟡 Carregar estados salvos
    QFile file(QDir::homePath() + "/.config/config_waybar/config.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine().trimmed();
            QStringList parts = line.split('=');
            if (parts.size() == 2) {
                QString key = parts[0];
                QString value = parts[1];

                if (key == "som") switchSom->setChecked(value == "true");
                else if (key == "cpu") switchCPU->setChecked(value == "true");
            }
        }
        file.close();
    } else {
        qWarning() << "⚠️ Não foi possível carregar o arquivo de configuração.";
    }
}

void WaybarConfig::saveConfig()
{
    QFile file(QDir::homePath() + "/.config/waybar/config.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << "som=" << (switchSom->isChecked() ? "true" : "false") << "\n";
        out << "cpu=" << (switchCPU->isChecked() ? "true" : "false") << "\n";
        file.close();
        QMessageBox::information(this, "Sucesso", "Configurações salvas com sucesso!");
    } else {
        QMessageBox::warning(this, "Erro", "Não foi possível salvar o arquivo de configuração.");
    }
}

