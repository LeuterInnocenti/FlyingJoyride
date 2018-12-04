//
// Created by Athos Innocenti on 29/11/2018.
//

#ifndef FLYJOYRIDE_SUBJECT_H
#define FLYJOYRIDE_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual void foo2() = 0;

protected:
    virtual ~Subject() {}
};

#endif //FLYJOYRIDE_SUBJECT_H