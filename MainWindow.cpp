// MainWindow.cpp
#include "MainWindow.h"

MainWindow::MainWindow(Controller *controller, QWidget *parent) : QWidget(parent), controller(controller) {
    newNoteButton = new QPushButton("New note", this);
    newCollectionButton = new QPushButton("New collection", this);
    saveButton = new QPushButton("Save note", this);
    saveButton->setGeometry(0, 100, 80, 30);
    saveButton->hide();
    saveCollectionButton = new QPushButton("Save collection", this);
    saveCollectionButton->setGeometry(0, 100, 120, 30);
    saveCollectionButton->hide();
    titleEdit = new QLineEdit(this);
    titleEdit->setPlaceholderText("Title");
    titleEdit->setGeometry(0, 40, 140, 30);
    titleEdit->hide();
    textEdit = new QLineEdit(this);
    textEdit->setPlaceholderText("Note text");
    textEdit->setGeometry(0, 70, 300, 30);
    textEdit->hide();
    comboBox = new QComboBox(this);
    newCollectionButton->setGeometry(150, 0, 110, 30);
    newNoteButton->setGeometry(260, 0, 80, 30);
    comboBox->setGeometry(0, 0, 140, 30);
    noteList = new QListWidget(this);
    noteList->setGeometry(0, 40, 300, 300);
    noteList->hide();

    QObject::connect(newNoteButton, &QPushButton::clicked, this, &MainWindow::showNoteFields);
    QObject::connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveNote);
    QObject::connect(newCollectionButton, &QPushButton::clicked, this, &MainWindow::showCollectionFields);
    QObject::connect(saveCollectionButton, &QPushButton::clicked, this, &MainWindow::addCollection);
    QObject::connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onCollectionSelected);

    initializeDefaultCollection(); // Initialize the default collection
    update();
}

void MainWindow::initializeDefaultCollection() {
    Collection *defaultCollection = new Collection("recently added");
    controller->addCollection(defaultCollection);
}

void MainWindow::addCollection() {
    QString title = titleEdit->text();
    Collection *collection = new Collection(title);
    controller->addCollection(collection);
    titleEdit->hide();
    saveCollectionButton->hide();
    HomePage();
}

void MainWindow::addNoteToCollection(Note *note, Collection *collection) {
    controller->addNoteToCollection(note, collection);
}

void MainWindow::showNoteFields() {
    newNoteButton->hide();
    newCollectionButton->hide();
    noteList->hide();
    titleEdit->show();
    textEdit->show();
    saveButton->show();
}

void MainWindow::showCollectionFields() {
    newNoteButton->hide();
    noteList->hide();
    newCollectionButton->hide();
    titleEdit->show();
    saveCollectionButton->show();
}

void MainWindow::saveNote() {
    QString title = titleEdit->text();
    QString text = textEdit->text();
    Note *note = new Note(title, text);
    addNoteToCollection(note, controller->getCollections().at(0));
    titleEdit->hide();
    textEdit->hide();
    saveButton->hide();
    HomePage();
}

void MainWindow::onCollectionSelected(int index) {
    noteList->clear();
    for (Note *note : controller->getCollections().at(index)->getNotes()) {
        noteList->addItem(note->getTitle());
    }
    noteList->show();
}

void MainWindow::HomePage() {
    newNoteButton->show();
    newCollectionButton->show();
    comboBox->show();
}