// Controller.cpp

#include "Controller.h"

Controller::Controller(QList<Collection*> collections) : collections(collections) {}

void Controller::addCollection(Collection *collection) {
    collections.append(collection);
    notify();
}

void Controller::addNoteToCollection(Note *note, Collection *collection) {
    collection->addNote(note);
    notify();
}

void Controller::addObserver(Observer *observer) {
    observers.append(observer);
}

void Controller::removeObserver(Observer *observer) {
    observers.removeOne(observer);
}

void Controller::notify() {
    for (Observer *observer : observers) {
        observer->update();
    }
}
QList<Collection*> Controller::getCollections() const {
    return collections;
}

