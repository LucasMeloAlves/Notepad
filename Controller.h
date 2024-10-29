// Controller.h

#ifndef NOTEPAD_CONTROLLER_H
#define NOTEPAD_CONTROLLER_H

#include <QList>
#include "Collection.h"
#include "Observer.h"

class Controller : public Observer {
public:
    explicit Controller(QList<Collection*> collections);
    void addCollection(Collection *collection);
    void addNoteToCollection(Note *note, Collection *collection);
    QList<Collection*> getCollections() const;
    void update() override;

private:
    QList<Collection*> collections;
};

#endif //NOTEPAD_CONTROLLER_H