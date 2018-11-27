//
// Created by Athos Innocenti on 27/11/2018.
//

#include "gtest/gtest.h"
#include "../Block.h"
#include "../NormalBlock.h"

class NormalBlockTest : public ::testing::Test {
protected:
    NormalBlock block;
};

TEST_F(NormalBlockTest, testColor) {
    ASSERT_EQ(sf::Color::Red, block.getFillColor());
}

TEST_F(NormalBlockTest, testSize) {
    ASSERT_EQ(sf::Vector2f(100, 80), block.getSize());
}