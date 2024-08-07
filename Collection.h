//
// Created by lucas on 06/08/24.
//


#ifndef NOTEPAD_COLLECTION_H
#define NOTEPAD_COLLECTION_H
#include <QObject>
#include <QString>
#include <QList>
#include "Note.h"

class Collection: public QObject
{
    Q_OBJECT
private:
    QString name;
    QList<Note*> notes;
public:
    Collection(QString name);

    void addNote(Note* note){
        notes.append(note);
    }
    void removeNote(Note* note){
        notes.removeOne(note);
    }
    QString getName() const{
        return name;
    }
    QList<Note*> getNotes() const{
        return notes;
    }
    void setName(QString name){
        this->name = name;
    }
    void add(Note* note){
        notes.append(note);
    }
    void remove(Note* note){
        notes.removeOne(note);
    }
};
#endif //NOTEPAD_COLLECTION_H
