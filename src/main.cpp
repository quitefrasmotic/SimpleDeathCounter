#include "main_widget.h"
#include <QApplication>
#include <QHotkey>
#include <iostream>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QHotkey hotkey(QKeySequence("Ctrl+Shift+Up"), true, &app);

    QObject::connect(&hotkey, &QHotkey::activated, qApp, [&]() {
        std::cout << "Shortcut pressed cout" << std::endl;
	});

    MainWidget window;
    window.show();
    
    return app.exec();
}
