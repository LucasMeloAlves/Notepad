//
// Created by lucas on 06/08/24.
//


#ifndef NOTEPAD_COLLECTION_H
#define NOTEPAD_COLLECTION_H
#include <QObject>
#include <QString>
#include <QList>
#include "Note.h"
#include "Subject.h"
#include "Observer.h"

class Collection: public Subject {
Q_OBJECT

private:
    QString name;
    QList<Note *> notes;
    QList<Observer *> observers;
public:
    Collection(QString name);

    void addNote(Note *note) {
        notes.append(note);//aggiunge elemento in coda
        notify();
    }

    void removeNote(Note *note) {
        notes.removeOne(note);
        notify();
    }

    QString getName() const {
        return name;
    }

    QList<Note *> getNotes() const {
        return notes;
    }

    void setName(QString name) {
        this->name = name;
    }

    void addObserver(Observer *observer) override {
        observers.append(observer);
    }

    void removeObserver(Observer *observer) override {
        observers.removeOne(observer);
    }


    void notify() override {
        for (auto observer: observers) {
            observer->update(notes.size());
        }
    }
};
#endif //NOTEPAD_COLLECTION_H
