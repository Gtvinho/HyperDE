#ifndef WAYBARCONFIG_H
#define WAYBARCONFIG_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>
#include<QCheckBox>
#include<QMap>
class WaybarConfig : public QWidget
{
    Q_OBJECT

public:
    WaybarConfig(QWidget *parent = nullptr);

private slots:

    void saveConfig();

private:
    QTextEdit *configEditor;

    QPushButton *saveButton;
//switch bottons
    QCheckBox *switchSom;
    QCheckBox *switchCPU;
    QCheckBox *switchMemoria;
    QMap<QString, QCheckBox*> switchesMap;
};

#endif // WAYBARCONFIG_H
