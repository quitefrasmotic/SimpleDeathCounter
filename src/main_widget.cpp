#include "main_widget.h"
#include "ui_main_widget.h"
#include <QHotkey>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>

using namespace std;

MainWidget::MainWidget(QWidget *parent) : QWidget(parent), ui(new Ui::MainWidget), deathShortcut(new QHotkey(this)) {
   ui->setupUi(this);
   setWindowTitle("SimpleDeathCounter");
   
   connect(this->ui->keySequenceEdit, &QKeySequenceEdit::keySequenceChanged, this, &MainWidget::onSetShortcut);
   connect(this->ui->setDeathsButton, &QPushButton::clicked, this, &MainWidget::onSetDeaths);
   
	connect(this->deathShortcut, &QHotkey::activated, this, &MainWidget::incrementDeaths);

   //// Data and config file management
   string deathsFileName = "deaths.txt";
   string configFileName = "config.txt";
   bool deathsFileExists = filesystem::exists(deathsFileName);
   bool configFileExists = filesystem::exists(configFileName);

   // Deaths file
   if (deathsFileExists) {
      ifstream deathsFile(deathsFileName);
      string pastDeaths;

      // This gets the first line of the file seemingly, and I'm not sure how to get other lines - for now this is okay, but I
      // will need to create a way to loop through lines in the future if I add more config values
      getline(deathsFile, pastDeaths);

      // Convert past deaths string to int
      currentDeaths = stoi(pastDeaths);
      this->ui->currentDeathsLabel->setNum(currentDeaths);

      cout << pastDeaths << endl;
      deathsFile.close();
   }
   else {
      cout << "Deaths file does not exist, creating fresh.." << endl;
      ofstream deathsFile(deathsFileName);
      deathsFile << "0";
      deathsFile.close();
   }

   // Config file
   if (configFileExists) {
      ifstream configFile(configFileName);
      string storedShortcutCombo;

      getline(configFile, storedShortcutCombo);
      QKeySequence shortcutCombo = QString::fromStdString(storedShortcutCombo);

      this->deathShortcut->setShortcut(shortcutCombo, true);
      this->ui->currentShortcutLabel->setText(shortcutCombo.toString());

      cout << shortcutCombo.toString().toStdString() << endl;
      configFile.close();
   }
   else {
      this->deathShortcut->setShortcut(QKeySequence("Ctrl+Shift+Up"), true);

      cout << "Config file does not exist, creating fresh.." << endl;
      ofstream configFile(configFileName);
      configFile << "Ctrl+Shift+Up";
      configFile.close();
   }

   cout << "Main widget started" << endl;
}

MainWidget::~MainWidget() {
   delete this->deathShortcut;
   delete ui;
}

void MainWidget::onSetDeaths() {
   currentDeaths = this->ui->deathsSpinBox->value();
   this->ui->currentDeathsLabel->setNum(currentDeaths);
}

void MainWidget::onSetShortcut(const QKeySequence &sequence) {
   this->deathShortcut->setShortcut(sequence, true);
   this->ui->currentShortcutLabel->setText(sequence.toString());
   cout << "Death shortcut set" << endl;
}

void MainWidget::incrementDeaths() {
   currentDeaths++;
   this->ui->currentDeathsLabel->setNum(currentDeaths);
   cout << "Incremented deaths - " + to_string(currentDeaths) << endl;
}
