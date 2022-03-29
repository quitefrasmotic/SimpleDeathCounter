#include "main_widget.h"
#include "ui_main_widget.h"
#include <QHotkey>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MainWidget), deathShortcut(new QHotkey(this)) {
   ui->setupUi(this);
   
   setWindowTitle("SimpleDeathCounter");
}


MainWidget::~MainWidget() {
   delete ui;
}
