//
// Created by lucas on 07/10/24.
//

#ifndef NOTEPAD_CONTROLLER_H
#define NOTEPAD_CONTROLLER_H
#include "Collection.h"

class Controller {
public:
    Controller(QList<Collection*> &collections);

    void addNoteToCollection(const QString &title, const QString &text, Collection *collection);

private:
    QList<Collection*> &collections;
};


#endif //NOTEPAD_CONTROLLER_H
