#include "WaybarConfig.h"
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>

WaybarConfig::WaybarConfig(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("HyprDE - Waybar Config");

    configEditor = new QTextEdit(this);
    loadButton = new QPushButton("Carregar Configuração", this);
    saveButton = new QPushButton("Salvar Configuração", this);

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(configEditor);
    layout->addWidget(loadButton);
    layout->addWidget(saveButton);

    connect(loadButton, &QPushButton::clicked, this, &WaybarConfig::loadConfig);
    connect(saveButton, &QPushButton::clicked, this, &WaybarConfig::saveConfig);
}

void WaybarConfig::loadConfig()
{
    QFile file(QDir::homePath() + "/.config/waybar/style.css");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        configEditor->setText(in.readAll());
        file.close();
    } else {
        QMessageBox::warning(this, "Erro", "Não foi possível abrir o arquivo de configuração.");
    }
}

void WaybarConfig::saveConfig()
{
    QFile file(QDir::homePath() + "/.config/waybar/style.css");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << configEditor->toPlainText();
        file.close();
        QMessageBox::information(this, "Sucesso", "Configuração salva com sucesso!");
    } else {
        QMessageBox::warning(this, "Erro", "Não foi possível salvar o arquivo.");
    }
}
