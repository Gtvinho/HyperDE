#ifndef WAYBARCONFIG_H
#define WAYBARCONFIG_H

#include <QWidget>
#include <QPushButton>
#include <QTextEdit>

class WaybarConfig : public QWidget
{
    Q_OBJECT

public:
    WaybarConfig(QWidget *parent = nullptr);

private slots:
    void loadConfig();
    void saveConfig();

private:
    QTextEdit *configEditor;
    QPushButton *loadButton;
    QPushButton *saveButton;
};

#endif // WAYBARCONFIG_H
