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


class Collection: public Subject {
Q_OBJECT

private:
    QString name;
    QList<Note *> notes;
    QList<Observer *> observers;
public:
    Collection(QString name);
    void addNote(Note *note);
    void removeNote(Note *note);
    QString getName() const;
    QList<Note *> getNotes() const;
    void setName(QString name);
    void addObserver(Observer *observer) override;
    void removeObserver(Observer *observer) override;
    void notify() override;
};
#endif //NOTEPAD_COLLECTION_H
