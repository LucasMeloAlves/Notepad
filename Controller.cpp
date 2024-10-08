//
// Created by lucas on 07/10/24.
//

#include "Controller.h"
Controller::Controller(QList<Collection*> &collections) : collections(collections) {}

void Controller::addNoteToCollection(const QString &title, const QString &text, Collection *collection) {
    Note *note = new Note(title, text);
    collection->addNote(note);
}