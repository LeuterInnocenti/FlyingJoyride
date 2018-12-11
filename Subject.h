//
// Created by Athos Innocenti on 29/11/2018.
//

#ifndef FLYJOYRIDE_SUBJECT_H
#define FLYJOYRIDE_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void subscribe(Observer *o) = 0;
    virtual void unsubscribe(Observer *o) = 0;
    virtual void notify() = 0;

    virtual ~Subject() {}
};

#endif //FLYJOYRIDE_SUBJECT_H