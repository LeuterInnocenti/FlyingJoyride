//
// Created by Athos Innocenti on 29/11/2018.
//

#ifndef FLYJOYRIDE_OBSERVER_H
#define FLYJOYRIDE_OBSERVER_H

class Observer {
public:
    virtual ~Observer() {}

    virtual void update() = 0;

    virtual void attach() = 0;
    virtual void detach() = 0;
};

#endif //FLYJOYRIDE_OBSERVER_H