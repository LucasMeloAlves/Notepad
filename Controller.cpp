// Controller.cpp

#include "Controller.h"

Controller::Controller(QList<Collection*> collections) : collections(collections) {}

void Controller::addCollection(Collection *collection) {
    collections.append(collection);
    update();
}

void Controller::addNoteToCollection(Note *note, Collection *collection) {
    collection->addNote(note);
    update();
}

QList<Collection*> Controller::getCollections() const {
    return collections;
}

void Controller::update() {
    // Implementa il comportamento di aggiornamento
}