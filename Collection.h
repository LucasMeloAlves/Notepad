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
                emit notify();
    }

    void removeNote(Note *note) {
        notes.removeOne(note);
        emit notify();
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
        //sistema il connect
        QObject::connect(this, &Collection::noteCountChanged, observer, &Observer::update);

    }

    void removeObserver(Observer *observer) override {
        observers.removeOne(observer);
        QObject::disconnect(this, &Collection::noteCountChanged, observer, &Observer::update);
    }
    int getNumNotes() const{
        return notes.size();
    }
    void notify() override {
        emit noteCountChanged(notes.size());
        }
signals:
    void noteCountChanged(int count);
};
#endif //NOTEPAD_COLLECTION_H
