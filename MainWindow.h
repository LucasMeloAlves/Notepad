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
#include <QLineEdit>

class MainWindow : public QWidget {
Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) {
        //button per aggiungere nuova nota
        newNoteButton = new QPushButton("New note", this);
        // Campi che rimangono nascosti e appaiono quando clicco il pulsante new note
        saveButton = new QPushButton("Salva Nota", this);
        saveButton->setGeometry(0, 100, 80, 30);
        saveButton->hide();
        titleEdit = new QLineEdit(this);
        titleEdit->setPlaceholderText("Titolo della nota");
        titleEdit->setGeometry(0, 40, 140, 30);
        titleEdit->hide();
        textEdit = new QLineEdit(this);
        textEdit->setPlaceholderText("Testo della nota");
        textEdit->setGeometry(0, 70, 300, 30);
        textEdit->hide();
        //comboBox per selezionare la collezione da visualizzare/aggiungere la nota
        comboBox = new QComboBox(this);
        newNoteButton->setGeometry(150, 0, 80, 30);
        noteListWidget = new QListWidget();
        comboBox->setGeometry(0, 0, 140, 30);
        //aggiungo una collezione di default(recently added)
        addCollection(new Collection("Recently added"));
        comboBox->addItem("Recently added");
        //quando clicco il pulasante new note mi appare una finestra con un campo di testo e uno per il titolo e un pulsante per salvare
        connect(newNoteButton, &QPushButton::clicked, this, &MainWindow::showNoteFields);
        connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveNote);
    }

    void addCollection(Collection *collection) {
        collections.append(collection);
        comboBox->addItem(collection->getName());
    }

    void addNoteToCollection(Note *note, Collection *collection) {
        collection->addNote(note);
    }

private slots:

    void showNoteFields() {
        newNoteButton->hide();
        titleEdit->show();
        textEdit->show();
        saveButton->show();
    }

    void saveNote() {
        QString title = titleEdit->text();
        QString text = textEdit->text();
        Note *note = new Note(title, text);
        }


        private:
        QList<Collection *> collections;
        QListWidget *noteListWidget;
        QPushButton *newNoteButton;
        QComboBox *comboBox;
        QLineEdit *titleEdit;
        QLineEdit *textEdit;
        QPushButton* saveButton;

};
#endif //NOTEPAD_MAINWINDOW_H
