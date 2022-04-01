#include "main_widget.h"
#include <QApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    cout << "Application started" << endl;

    MainWidget window;
    window.show();
    
    return app.exec();
}
