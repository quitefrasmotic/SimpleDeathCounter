#include "main_widget.h"
#include "ui_main_widget.h"
#include <QHotkey>
#include <iostream>
#include <qwidget.h>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MainWidget), deathShortcut(new QHotkey(this)) {
   ui->setupUi(this);
   
   connect(this->ui->keySequenceEdit, &QKeySequenceEdit::keySequenceChanged, this, &MainWidget::onSetShortcut);
	connect(this->deathShortcut, &QHotkey::activated, this, &MainWidget::incrementDeaths);
   
   setWindowTitle("SimpleDeathCounter");
}

MainWidget::~MainWidget() {
   delete this->deathShortcut;
   delete ui;
}

void MainWidget::showEvent(QShowEvent *event)
{
    QWidget::showEvent(event);
    onShowEvent();
}

void MainWidget::onShowEvent() {
   if (firstOpen == false) {
      return;
   }
   firstOpen = false;
   this->deathShortcut->setShortcut(QKeySequence("Ctrl+Shift+Up"), true);
   currentDeaths = 0;
}

void MainWidget::onSetDeaths() {

}

void MainWidget::onSetShortcut(const QKeySequence &sequence) {
   this->deathShortcut->setShortcut(sequence, true);
   std::cout << "Death shortcut set" << std::endl;
}

void MainWidget::incrementDeaths() {
   currentDeaths++;
   std::cout << "Incremented deaths - " + std::to_string(currentDeaths) << std::endl;
}
