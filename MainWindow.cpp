#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) {
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
comboBox->setGeometry(0, 0, 140, 30);
//aggiungo una collezione di default(recently added)
addCollection(new Collection("Recently added"));
//quando clicco il pulasante new note mi appare una finestra con un campo di testo e uno per il titolo e un pulsante per salvare
connect(newNoteButton, &QPushButton::clicked, this, &MainWindow::showNoteFields);
connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveNote);
noteList = new QListWidget(this);
noteList->setGeometry(0, 40, 300, 300);
noteList->hide();
connect(comboBox, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::onCollectionSelected);
// Seleziona la prima collezione per iniziare
if (comboBox->count() > 0) {
comboBox->setCurrentIndex(0);

}
}

void MainWindow::addCollection(Collection *collection){
        collections.append(collection);
        comboBox->addItem(collection->getName());
}

void MainWindow::addNoteToCollection(Note *note, Collection *collection) {
    collections.at(0)->addNote(note);
}



void MainWindow::showNoteFields() {
    newNoteButton->hide();
    noteList->hide();
    titleEdit->show();
    textEdit->show();
    saveButton->show();
}

void MainWindow::saveNote() {
    QString title = titleEdit->text();
    QString text = textEdit->text();
    Note *note = new Note(title, text);
    //aggiungo la nota a recently added che è sempre la prima collezione della lista
    addNoteToCollection(note, collections.at(0));
    titleEdit->hide();
    textEdit->hide();
    saveButton->hide();
    newNoteButton->show();
    noteList->show();
}
void MainWindow::onCollectionSelected(int index) {
    noteList->clear(); //pulisco la lista
    for (auto note: collections.at(index)->getNotes()) {
        noteList->addItem(note->getTitle());
    }
    noteList->show();
}
