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
    Character testPlayer;

    sf::CircleShape testEnemyBullet;
    sf::CircleShape testBullet;

    std::vector<sf::CircleShape> bullets;
    std::vector<std::unique_ptr<Block>> blocks;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<sf::CircleShape> enemyBullets;

    sf::Texture testPlayerTexture;

    BlockFactory factoryB;
    EnemyFactory factoryE;

    bool collision = false;
};

TEST_F(GameTest, testSettingConst) {
    ASSERT_EQ(1.7f, game.getBulletSpeed());
    ASSERT_EQ(63.0f, game.getLevelGround());
    ASSERT_EQ(1.3f, game.getShootTime());
    ASSERT_EQ(0.120f, game.getRateIncreaser());
    ASSERT_EQ(0.1f, game.getSpeedIncreaser());
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

TEST_F(GameTest, testCollisionPlayerNormalBlock) {
    std::unique_ptr<Block> testBlock = factoryB.createBlock(BlockType::NormalBlock);
    game.randomPos();
    testBlock->setPosition(sf::Vector2f(2 * game.getWindowSize().x, game.getRandomY()));
    testPlayerTexture.loadFromFile("frame-1.png");
    testPlayer.setPlayerTexture(testPlayerTexture);
    testPlayer.setPlayerPosition(game.getWindowSize().x, game.getRandomY());
    testBlock->move(-game.getSpeed().x, 0);
    if (testBlock->getGlobalBounds().intersects(testPlayer.getBound())) {
        if (game.getIsPowerUpOn())
            ASSERT_FALSE(game.getIsPowerUpOn());
        else
            ASSERT_TRUE(collision);
    }
}

TEST_F(GameTest, testCollisionPlayerPowerUpBlock) {
    std::unique_ptr<Block> testBlock = factoryB.createBlock(BlockType::PowerUpBlock);
    game.randomPos();
    testBlock->setPosition(sf::Vector2f(2 * game.getWindowSize().x, game.getRandomY()));
    testPlayerTexture.loadFromFile("frame-1.png");
    testPlayer.setPlayerTexture(testPlayerTexture);
    testPlayer.setPlayerPosition(game.getWindowSize().x, game.getRandomY());
    testBlock->move(-game.getSpeed().x, 0);
    if (testBlock->getGlobalBounds().intersects(testPlayer.getBound()))
        ASSERT_EQ(true, game.getIsPowerUpOn());
}

TEST_F(GameTest, testCollisionPlayerShootingEnemy) {
    std::unique_ptr<Enemy> testEnemy = factoryE.createEnemy(EnemyType::ShootingEnemy);
    game.randomPos();
    testEnemy->setPosition(sf::Vector2f(2 * game.getWindowSize().x, game.getRandomY()));
    testPlayerTexture.loadFromFile("frame-1.png");
    testPlayer.setPlayerTexture(testPlayerTexture);
    testPlayer.setPlayerPosition(game.getWindowSize().x, game.getRandomY());
    testEnemy->move(-game.getSpeed().x, 0);
    if (testEnemy->getGlobalBounds().intersects(testPlayer.getBound())) {
        if (game.getIsPowerUpOn())
            ASSERT_FALSE(game.getIsPowerUpOn());
        else
            ASSERT_TRUE(collision);
    }
}

TEST_F(GameTest, testCollisionPlayerFlyingEnemy) {
    std::unique_ptr<Enemy> testEnemy = factoryE.createEnemy(EnemyType::FlyingEnemy);
    game.randomPos();
    testEnemy->setPosition(sf::Vector2f(2 * game.getWindowSize().x, game.getRandomY()));
    testPlayerTexture.loadFromFile("frame-1.png");
    testPlayer.setPlayerTexture(testPlayerTexture);
    testPlayer.setPlayerPosition(game.getWindowSize().x, game.getRandomY());
    testEnemy->move(-game.getSpeed().x, 0);
    if (testEnemy->getGlobalBounds().intersects(testPlayer.getBound())) {
        if (game.getIsPowerUpOn())
            ASSERT_FALSE(game.getIsPowerUpOn());
        else
            ASSERT_TRUE(collision);
    }
}

// Bullet - Enemy
TEST_F(GameTest, testCollisionBulletShootingEnemy) {
    std::unique_ptr<Enemy> testEnemy = factoryE.createEnemy(EnemyType::ShootingEnemy);
    game.randomPos();
    testEnemy->setPosition(sf::Vector2f(2 * game.getWindowSize().x, game.getRandomY()));
    testBullet.setPosition(game.getWindowSize().x, game.getRandomY());
    testEnemy->move(-game.getSpeed().x, 0);
    testBullet.move(game.getSpeed().x, 0);
    if (testEnemy->getGlobalBounds().intersects(testBullet.getGlobalBounds()))
        ASSERT_TRUE(collision);
}