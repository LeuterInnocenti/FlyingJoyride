//
// Created by Athos Innocenti on 26/11/2018.
//

#include "gtest/gtest.h"
#include "../Character.h"

class PlayerTest : public ::testing::Test {
protected:
    Character player;
};

TEST_F(PlayerTest, testColor) {
    if (player.getDeath())
        ASSERT_EQ(sf::Color::White, player.getColor());
    else
        ASSERT_EQ(sf::Color::Blue, player.getColor());
}

TEST_F(PlayerTest, testSize) {
    ASSERT_EQ(sf::Vector2f(100, 50), player.getPlayerSize());
}

TEST_F(PlayerTest, testPosition) {
    ASSERT_EQ(sf::Vector2f(50, 100), player.getPlayerPosition());
}