//
// Created by Athos Innocenti on 27/11/2018.
//

#include "gtest/gtest.h"
#include "../Window.h"

TEST(WindowTest, testSize) {
    Window gameWindow;
    EXPECT_EQ(sf::Vector2u(400, 600), gameWindow.getWindowSize());
}