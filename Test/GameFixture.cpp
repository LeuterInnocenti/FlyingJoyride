//
// Created by Athos Innocenti on 27/11/2018.
//

#include "gtest/gtest.h"
#include "../Game.h"

class GameTest : public ::testing::Test {
protected:
    Game game;
    Window window;
    Enemy testEnemy;
    Block testBlock;
    class NormalBlock testNormalBlock;
    class ShootingEnemy testShootingEnemy;
    class FlyingEnemy testFlyingEnemy;
    Character testPlayer;
    sf::CircleShape testEnemyBullet;
    sf::CircleShape testBullet;
    std::vector<sf::CircleShape> bullets;
    std::vector<std::unique_ptr<Block>> blocks;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<sf::CircleShape> enemyBullets;
    sf::Texture testPlayerTexture;

};

TEST_F(GameTest, testSettingConst) {
    ASSERT_EQ(1.7f, game.getBulletSpeed());
    ASSERT_EQ(63.0f, game.getLevelGround());
    ASSERT_EQ(1.3f, game.getShootTime());
}

TEST_F(GameTest, testAssignment) {
    ASSERT_EQ(sf::Vector2f(0.7, 0.8), game.getSpeed());
    ASSERT_TRUE(game.getCreationRate() <= 1.4f);
    ASSERT_TRUE(game.randomCreation() >= 0 && game.randomCreation() <= 3);
    ASSERT_TRUE(game.randomPos() >= 0 && game.randomPos() <= game.getMaxY());
}

TEST_F(GameTest, testDeletingBlocks) {
    int containerBlockSize = game.getBlocksContainerSize();
    testBlock.setPosition(-testBlock.getGlobalBounds().width, testBlock.getPosition().y);
    // testBlock ha la minima X per cui dovrà essere eliminato
    if (testBlock.getPosition().x + testBlock.getGlobalBounds().width < 0) {
        blocks.erase(blocks.begin() + 0);
        ASSERT_TRUE(containerBlockSize > game.getBlocksContainerSize());
    }
}

TEST_F(GameTest, testDeletingEnemies) {
    int containerEnemiesSize = game.getEnemiesContainerSize();
    testEnemy.setPosition(-testEnemy.getGlobalBounds().width, testEnemy.getPosition().y);
    // testEnemy ha la minima X per cui dovrà essere eliminato
    if (testEnemy.getPosition().x + testEnemy.getGlobalBounds().width < 0) {
        enemies.erase(enemies.begin() + 0);
        ASSERT_TRUE(containerEnemiesSize > game.getEnemiesContainerSize());
    }
}

TEST_F(GameTest, testDeletingEnemiesBullets) {
    int containerEnemiesBulletsSize = game.getEnemiesBulletsContainerSize();
    testEnemyBullet.setPosition(-testEnemyBullet.getGlobalBounds().width, testEnemyBullet.getPosition().y);
    enemyBullets.emplace_back(testEnemyBullet);
    // testEnemyBullet ha la minima X per cui dovrà essere eliminato
    if (testEnemyBullet.getPosition().x + testEnemyBullet.getGlobalBounds().width < 0) {
        enemyBullets.erase(enemyBullets.begin() + 0);
        ASSERT_TRUE(containerEnemiesBulletsSize > game.getEnemiesBulletsContainerSize());
    }
}

TEST_F(GameTest, testDeletingBullets) {
    int containerBulletsSize = game.getBulletsContainerSize();
    testBullet.setPosition(-testBullet.getGlobalBounds().width, testBullet.getPosition().y);
    bullets.emplace_back(testBullet);
    // testBullet ha la minima X per cui dovrà essere eliminato
    if (testBullet.getPosition().x + testBullet.getGlobalBounds().width < 0) {
        bullets.erase(bullets.begin() + 0);
        ASSERT_TRUE(containerBulletsSize > game.getBulletsContainerSize());
    }
}

TEST_F(GameTest, testCollisionPlayerNormalBlock) {
    testPlayerTexture.loadFromFile("frame-1.png");
    testPlayer.setPlayerTexture(testPlayerTexture);
    testNormalBlock.setPosition(100,100);
    testPlayer.setPlayerPosition(100, 100);
    ASSERT_TRUE(testNormalBlock.getGlobalBounds().intersects(testPlayer.getBound()));
}

TEST_F(GameTest, testCollisionPlayerShootingEnemy) {
    testPlayerTexture.loadFromFile("frame-1.png");
    testPlayer.setPlayerTexture(testPlayerTexture);
    testShootingEnemy.setPosition(100,100);
    testPlayer.setPlayerPosition(100, 100);
    ASSERT_TRUE(testShootingEnemy.getGlobalBounds().intersects(testPlayer.getBound()));
}

TEST_F(GameTest, testCollisionPlayerFlyingEnemy) {
    testPlayerTexture.loadFromFile("frame-1.png");
    testPlayer.setPlayerTexture(testPlayerTexture);
    testFlyingEnemy.setPosition(100,100);
    testPlayer.setPlayerPosition(100, 100);
    ASSERT_TRUE(testFlyingEnemy.getGlobalBounds().intersects(testPlayer.getBound()));
}

TEST_F(GameTest, testMovingPlayer) {
    float lg = game.getLevelGround();
    game.movePlayer();
    ASSERT_TRUE(testPlayer.getPlayerPosition().y >= 0 &&
                testPlayer.getPlayerPosition().y <= (window.getWindowSize().y - lg));
}

TEST_F(GameTest, testBullet) {
    game.createBullet();
    ASSERT_EQ(sf::Color::Black, game.getBullets()[0].getFillColor());
    ASSERT_EQ(10, game.getBullets()[0].getRadius());
}