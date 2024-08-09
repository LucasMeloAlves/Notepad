//
// Created by lucas on 07/08/24.
//

#ifndef NOTEPAD_COLLECTIONCOUNT_H
#define NOTEPAD_COLLECTIONCOUNT_H

#include <QObject>
#include <QList>
#include "Observer.h"
#include "Collection.h"

class CollectionCount : public Observer {
Q_OBJECT

public:
    CollectionCount(Collection* collection);
    void addCollection(Collection* collection){
        collections.append(collection);
        collection->addObserver(this);
    }

    void removeCollection(Collection* collection){
        collections.removeOne(collection);
        collection->removeObserver(this);
    }

public slots:
    void update() override{

    }

private:

    QList<Collection*> collections;
};


#endif //NOTEPAD_COLLECTIONCOUNT_H