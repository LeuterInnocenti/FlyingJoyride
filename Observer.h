//
// Created by Athos Innocenti on 29/11/2018.
//

#ifndef FLYJOYRIDE_OBSERVER_H
#define FLYJOYRIDE_OBSERVER_H

class Observer {
public:
    virtual void foo1() = 0;

protected:
    virtual ~Observer() {}
};

#endif //FLYJOYRIDE_OBSERVER_H