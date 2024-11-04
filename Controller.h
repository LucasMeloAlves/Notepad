// Controller.h

#ifndef NOTEPAD_CONTROLLER_H
#define NOTEPAD_CONTROLLER_H

#include <QList>
#include "Collection.h"
#include "Observer.h"

class Controller:public Subject{

public:
    explicit Controller(QList<Collection*> collections);
    void addCollection(Collection *collection);
    void addNoteToCollection(Note *note, Collection *collection);
    QList<Collection*> getCollections() const;
    void notify() override;
    void removeObserver(Observer* observer) override;
    void addObserver(Observer* observer) override;

private:
    QList<Collection*> collections;
    QList<Observer*> observers;
};

#endif //NOTEPAD_CONTROLLER_H