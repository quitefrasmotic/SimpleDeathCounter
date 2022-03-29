#include "main_widget.h"
#include "ui_main_widget.h"
#include <QHotkey>
#include <iostream>
#include <fstream>

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MainWidget), deathShortcut(new QHotkey(this)) {
   ui->setupUi(this);
   
   connect(this->ui->keySequenceEdit, &QKeySequenceEdit::keySequenceChanged, this, &MainWidget::onSetShortcut);
   connect(this->ui->setDeathsButton, &QPushButton::clicked, this, &MainWidget::onSetDeaths);
   
	connect(this->deathShortcut, &QHotkey::activated, this, &MainWidget::incrementDeaths);
   
   setWindowTitle("SimpleDeathCounter");
   std::cout << "Program started" << std::endl;
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
   currentDeaths = this->ui->deathsSpinBox->value();
   this->ui->currentDeathsLabel->setNum(currentDeaths);
}

void MainWidget::onSetShortcut(const QKeySequence &sequence) {
   this->deathShortcut->setShortcut(sequence, true);
   this->ui->currentShortcutLabel->setText(sequence.toString());
   std::cout << "Death shortcut set" << std::endl;
}

void MainWidget::incrementDeaths() {
   currentDeaths++;
   this->ui->currentDeathsLabel->setNum(currentDeaths);
   std::cout << "Incremented deaths - " + std::to_string(currentDeaths) << std::endl;
}
