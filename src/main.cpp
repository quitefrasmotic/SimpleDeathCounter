#include "main_widget.h"
#include <QApplication>
#include <QHotkey>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    std::cout << "Application started" << std::endl;

    MainWidget window;
    window.show();
    
    return app.exec();
}
