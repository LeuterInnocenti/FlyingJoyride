//
// Created by Athos Innocenti on 10/12/2018.
//

#ifndef FLYJOYRIDE_DISPLAYELEMENT_H
#define FLYJOYRIDE_DISPLAYELEMENT_H

#include <SFML/Graphics/RenderWindow.hpp>

class DisplayElement {
public:
    virtual void draw() = 0;

protected:
    virtual  ~DisplayElement() {}
};

#endif //FLYJOYRIDE_DISPLAYELEMENT_H