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

    // Criação dos switches
    switchModoEscuro = new QCheckBox("Modo escuro", this);
    switchSom = new QCheckBox("Som", this);
    switchCPU = new QCheckBox("CPU", this);
    switchMemoria = new QCheckBox("Memória", this);

    // Carregar estilo do arquivo QSS e aplicar a todos os switches
    QString stylePath = QCoreApplication::applicationDirPath() + "/../Styles/StylesCode/StyleCheckBox.qss";
    QFile styleFile(stylePath);
    if (styleFile.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream in(&styleFile);
        QString style = in.readAll();
        switchModoEscuro->setStyleSheet(style);
        switchSom->setStyleSheet(style);
        switchCPU->setStyleSheet(style);
        switchMemoria->setStyleSheet(style);
        styleFile.close();
    } else {
        qWarning() << "❌ Não foi possível carregar o estilo:" << stylePath;
    }

    // Criar mapa para associar nomes às checkboxes
    switchesMap.insert("modo_escuro", switchModoEscuro);
    switchesMap.insert("som", switchSom);
    switchesMap.insert("cpu", switchCPU);
    switchesMap.insert("memoria", switchMemoria);

    // Layout
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(switchModoEscuro);
    layout->addWidget(switchSom);
    layout->addWidget(switchCPU);
    layout->addWidget(switchMemoria);

    // Botão salvar
    saveButton = new QPushButton("Salvar Configuração", this);
    layout->addWidget(saveButton);

    setLayout(layout);

    // Conexões
    connect(saveButton, &QPushButton::clicked, this, &WaybarConfig::saveConfig);
}

void WaybarConfig::saveConfig()
{
    QFile file(QDir::homePath() + "/.config/waybar/config.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (auto it = switchesMap.constBegin(); it != switchesMap.constEnd(); ++it) {
            out << it.key() << "=" << (it.value()->isChecked() ? "true" : "false") << "\n";
        }
        file.close();
        QMessageBox::information(this, "Sucesso", "Configuração salva com sucesso!");
    } else {
        QMessageBox::warning(this, "Erro", "Não foi possível salvar o arquivo.");
    }
}

