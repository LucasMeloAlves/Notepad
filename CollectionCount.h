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

public slots:
    void update(int count) override{}
};


#endif //NOTEPAD_COLLECTIONCOUNT_H