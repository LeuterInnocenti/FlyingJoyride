//
// Created by Athos Innocenti on 27/11/2018.
//

#include "gtest/gtest.h"
#include "../Game.h"

class GameTest : public ::testing::Test {
protected:
    Game game;
    Window window;
    Block testBlock;
    Character testPlayer;
};

TEST_F(GameTest, testSettingConst) {
    ASSERT_EQ(1.7f, game.getBulletSpeed());
    ASSERT_EQ(0.7f, game.getG());
    ASSERT_EQ(1.8f, game.getJump());
    ASSERT_EQ(63.0f, game.getLevelGround());
    ASSERT_EQ(1.3f, game.getShootTime());
}

TEST_F(GameTest, testAssignment) {
    ASSERT_EQ(sf::Vector2f(0.7, 0), game.getSpeed());
    ASSERT_TRUE(game.getCreationRate() <= 1.4f);
    ASSERT_TRUE(game.randomCreation() >= 0 && game.randomCreation() <= 3);
    ASSERT_TRUE(game.randomPos() >= 0 && game.randomPos() <= game.getMaxY());
}

TEST_F(GameTest, testDeletingBlocks) {
    int containerSize = game.getContainerSize();
    testBlock.setPosition(-testBlock.getSize().x, testBlock.getPosition().y);
    // testBlock ha la minima X per cui dovrà essere eliminato
    if (testBlock.getPosition().x + testBlock.getSize().x < 0) {
        game.eraseB(0);
        ASSERT_TRUE(containerSize > game.getContainerSize());
    }
}

TEST_F(GameTest, testMovingPlayer) {
    float lg = game.getLevelGround();
    if (game.movePlayer()) {
        ASSERT_TRUE(testPlayer.getPlayerPosition().y >= 0 &&
                    testPlayer.getPlayerPosition().y <= (window.getWindowSize().y - lg));
    }
}

TEST_F(GameTest, testBullet) {
    game.createBullet();
    ASSERT_EQ(sf::Color::Black, game.getBullets()[0].getFillColor());
    ASSERT_EQ(10, game.getBullets()[0].getRadius());
}