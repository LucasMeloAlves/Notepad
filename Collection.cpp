#include "Collection.h"

Collection::Collection(QString name){
this->name = name;
}

void Collection::addNote(Note *note) {
    notes.append(note);//aggiunge elemento in coda
    notify();
}

void Collection::removeNote(Note *note) {
    notes.removeOne(note);
    notify();
}

QString Collection::getName() const {
    return name;
}

QList<Note *> Collection::getNotes() const {
    return notes;
}

void Collection::setName(QString name) {
    this->name = name;
}

void Collection::addObserver(Observer *observer){
observers.append(observer);
}

void Collection::removeObserver(Observer *observer){
observers.removeOne(observer);
}

void Collection::notify(){
for (auto observer: observers) {
observer->update(notes.size());
}
}