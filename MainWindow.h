//
// Created by lucas on 09/08/24.
//

#ifndef NOTEPAD_MAINWINDOW_H
#define NOTEPAD_MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QListWidget>
#include "Note.h"
#include "Collection.h"
#include "Observer.h"
#include <QPushButton>
#include <QComboBox>

class MainWindow : public QWidget {


public:
    MainWindow(QWidget* parent = nullptr){
        QVBoxLayout* vLayout = new QVBoxLayout(this);
        QHBoxLayout* hLayout = new QHBoxLayout(this);
        button = new QPushButton("New note", this);
        comboBox = new QComboBox( this);
        //connect(newNote, &QPushButton::clicked, this, &MainWindow::Note);
        button->setGeometry(150, 0, 80, 30);
        //hLayout->addWidget(button);
        noteListWidget = new QListWidget();
        //layout->addWidget(noteListWidget);
        comboBox->setGeometry(0, 0, 140, 30);
        comboBox->addItem("Recently added");
        //hLayout->addWidget(button);
        //hLayout->addWidget(comboBox);

    }

private:
    Collection* workCollection;
    Collection* personalCollection;
    QListWidget* noteListWidget;
    QPushButton* button;
    QComboBox* comboBox;
};
#endif //NOTEPAD_MAINWINDOW_H
