//
// Created by lucas on 06/08/24.
//

#ifndef NOTEPAD_SUBJECT_H
#define NOTEPAD_SUBJECT_H
#include <QObject>
#include <QList>
#include "Observer.h"

class Subject : public QObject {
Q_OBJECT

public:
    virtual void addObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notify() = 0;

private:
    QList<Observer*> observers;
};
#endif //NOTEPAD_SUBJECT_H