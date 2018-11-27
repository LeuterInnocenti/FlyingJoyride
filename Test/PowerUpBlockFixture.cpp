//
// Created by Athos Innocenti on 27/11/2018.
//

#include "gtest/gtest.h"
#include "../Block.h"
#include "../PowerUpBlock.h"

class PowerUpBlockTest : public ::testing::Test {
protected:
    PowerUpBlock block;
};

TEST_F(PowerUpBlockTest, testColor) {
    ASSERT_EQ(sf::Color::Yellow, block.getFillColor());
}

TEST_F(PowerUpBlockTest, testSize) {
    ASSERT_EQ(sf::Vector2f(100, 80), block.getSize());
}