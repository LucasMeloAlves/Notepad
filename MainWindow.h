// MainWindow.h

#ifndef NOTEPAD_MAINWINDOW_H
#define NOTEPAD_MAINWINDOW_H

#include <QApplication>
#include <QWidget>
#include <QObject>
#include <QVBoxLayout>
#include <QListWidget>
#include "Note.h"
#include "Collection.h"
#include <QPushButton>
#include <QComboBox>
#include <QLineEdit>
#include "Controller.h"

class MainWindow : public QWidget {
Q_OBJECT

public:
    explicit MainWindow(Controller *controller, QWidget *parent = nullptr);
    void HomePage();
    void addNoteToCollection(Note *note, Collection *collection);
    void initializeDefaultCollection();
private slots:
    void showNoteFields();
    void saveNote();
    void onCollectionSelected(int index);
    void addCollection();
    void showCollectionFields();

private:
    Controller *controller;
    QPushButton *newNoteButton;
    QComboBox *comboBox;
    QLineEdit *titleEdit;
    QLineEdit *textEdit;
    QPushButton *saveButton;
    QListWidget *noteList;
    QPushButton *newCollectionButton;
    QPushButton *saveCollectionButton;
};

#endif //NOTEPAD_MAINWINDOW_H