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
#include "Observer.h"

class MainWindow : public QWidget{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void addCollection(Collection *collection);
    void addNoteToCollection(Note *note, Collection *collection);


private slots:
    void showNoteFields();
    void saveNote();
    void onCollectionSelected(int index);

private:
        QList<Collection*> collections;
        QPushButton *newNoteButton;
        QComboBox *comboBox;
        QLineEdit *titleEdit;
        QLineEdit *textEdit;
        QPushButton *saveButton;
        QListWidget *noteList;

};
#endif //NOTEPAD_MAINWINDOW_H
