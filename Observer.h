//
// Created by lucas on 06/08/24.
//

#ifndef NOTEPAD_OBSERVER_H
#define NOTEPAD_OBSERVER_H

#include <QWidget>

class Observer : public QWidget {
    Q_OBJECT

public slots:
    virtual void update() = 0;
};
#endif //NOTEPAD_OBSERVER_H
