#ifndef MAIN_WIDGET_H
#define MAIN_WIDGET_H

#include <QWidget>
#include <QHotkey>

namespace Ui {
    class MainWidget;
}

class MainWidget : public QWidget {
    Q_OBJECT

public:
    explicit MainWidget(QWidget* parent = nullptr);
    ~MainWidget();
    
    int currentDeaths;

private slots:
    void onSetDeaths();
    void onSetShortcut();
    void incrementDeaths();

private:
    Ui::MainWidget *ui;
    QHotkey *deathShortcut;
};

#endif
