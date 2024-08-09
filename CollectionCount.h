//
// Created by lucas on 07/08/24.
//

#ifndef NOTEPAD_COLLECTIONCOUNT_H
#define NOTEPAD_COLLECTIONCOUNT_H

#include <QObject>
#include <QList>
#include "Observer.h"
#include "Collection.h"
#include <iostream>

class CollectionCount : public Observer {
Q_OBJECT

public:
    CollectionCount(){}

    int draw(const Collection& collection) const{
        return collection.getNumNotes();
    }

public slots:
    void update(int count) override{
        std::cout << count << std::endl;
    }

};


#endif //NOTEPAD_COLLECTIONCOUNT_H