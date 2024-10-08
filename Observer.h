//
// Created by lucas on 06/08/24.
//

#ifndef NOTEPAD_OBSERVER_H
#define NOTEPAD_OBSERVER_H



class Observer: public QObject{
    Q_OBJECT
public:
    virtual ~Observer() = default;
    virtual void update(int count) = 0;
};
#endif //NOTEPAD_OBSERVER_H