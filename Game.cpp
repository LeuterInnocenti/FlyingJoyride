//
// Created by Athos Innocenti on 30/10/2018.
//

#include "Game.h"

#include <iostream>

const int Game::textSize = 30;
const float Game::shootTime = 1.3f;
const float Game::bulletSpeed = 1.7f;
const float Game::levelGround = 63.0f;
const float Game::speedIncreaser = 0.1;
const float Game::rateIncreaser = 0.120;

Game::Game() : window("FlyingJoyride", sf::Vector2u(1080, 720)), windowSize(window.getWindowSize()), player(),
               isCreated(false), isPowerUpOn(false), isEnemyCreated(false), speedPowerUp(false),killed(0), jump(1.8),
               g(0.7), n(1), count(0), counter(1), blockX(100), creationRate(1.4f), speed(sf::Vector2f(0.7, 0.8)),
               textCount(0), tollerance(2), score(0), creationLimit(150), speedLimit(20),
               playerClock(), objectClock(), scoreClock(), controlPowerUp(), enemyClock(), defectClock(),
               factoryB(), factoryE() {

    font1.loadFromFile("arial.ttf");
    font2.loadFromFile("comic.ttf");
    backgroundTexture.loadFromFile("Background.png");
    backgroundTexture.setRepeated(true);
    background.setTexture(backgroundTexture);
    background.setTextureRect(sf::IntRect(0, 0, (500 * windowSize.x), windowSize.y + static_cast<int>(levelGround)));
    background.setScale(0.675, 0.95);

    playerTexture1.loadFromFile("frame-1.png");
    playerTexture2.loadFromFile("frame-2.png");
    puPlayerTexture1.loadFromFile("puframe-1.png");
    puPlayerTexture2.loadFromFile("puframe-2.png");
    dePlayerTexture1.loadFromFile("deframe-1.png");
    dePlayerTexture2.loadFromFile("deframe-2.png");
    fireTexture1.loadFromFile("fire1.png");
    fireTexture2.loadFromFile("fire2.png");
    fireSprite.setScale(0.3, 0.3);
    player.setPlayerTexture(playerTexture1);

    fEnemyTexture.loadFromFile("fenemy1.png");
    sEnemyTexture.loadFromFile("senemy1.png");
    shootBuffer.loadFromFile("shoot.wav");
    powerUpBuffer.loadFromFile("powerup.wav");
    enemyDeadBuffer.loadFromFile("enemydead.wav");
    shootSound.setBuffer(shootBuffer);
    shootSound.setVolume(20.0f);
    powerUpSound.setBuffer(powerUpBuffer);
    enemyDeadSound.setBuffer(enemyDeadBuffer);

    music.openFromFile("marioMusic.ogg");
    music.setLoop(true);
    music.play();

    srand((unsigned) time(nullptr));
    maxY = static_cast<int>(windowSize.y - (levelGround + blockX));
}

Game::~Game() {
    blocks.clear();
    enemies.clear();
    bullets.clear();
    enemyBullets.clear();
}

void Game::update() {
    window.update();
    background.move(-speed.x, 0);
    achievementText.move(-speed.x * 1.5f, 0);

    if (player.getDeath() && textCount == 0) {
        file.open("score.txt", std::ios::out | std::ios::app);
        file << std::endl;
        file << "Score: " << score;
        file.close();
        textCount++;
        music.openFromFile("mariodie.ogg");
        music.setLoop(false);
        music.play();
    }

    createObjects();
    moveObject();
    movePlayer();
    deleteObject();
    handleText();

    setScore(score);
    setKilled(killed);

    if (!speedPowerUp) {
        if (!player.getDeath())
            collision();
        shoot();
        if (scoreClock.getElapsedTime().asSeconds() >= 1.0f && !player.getDeath()) {
            // ogni secondo score aumenta di 1
            score++;
            notify();
            scoreClock.restart();
        }
    } else if (scoreClock.getElapsedTime().asSeconds() >= 0.1 && !player.getDeath()) {
        score++;
        notify();
        scoreClock.restart();
    }
    // ogni volta che score è multiplo di speedLimit aumenta speed
    if (score >= n * speedLimit) {
        speed.x += speedIncreaser;
        if (score <= creationLimit)
            // oltre creationLimit i blocchi sarebbero troppo vicini
            creationRate -= rateIncreaser;
        n++;
    }
    if (isDefectOn && defectClock.getElapsedTime().asSeconds() >= 10.0f) {
        isDefectOn = false;
        jump = -jump;
        g = -g;
    }
    if (speedPowerUp && speedClock.getElapsedTime().asSeconds() >= 5.0f) {
        speedPowerUp = false;
        speed = oldSpeed;
    }
    if (score >= 200 && !speedPowerUp && count == 0) {
        music.openFromFile("marioSpeed.ogg");
        music.setLoop(true);
        music.play();
        count++;
    }
    if (speedPowerUp)
        fireAnimation();
}

// gestione del testo
void Game::handleText() {
    text.setFont(font1);
    text.setString("Score : ");
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(25);
    text.setPosition(10, 5);

    scoreText.setFont(font1);
    scoreText.setFillColor(sf::Color::Black);
    scoreText.setCharacterSize(25);
    scoreText.setPosition(100, 5);
    scoreText.setString(std::to_string(score));

    gameOver.setFont(font2);
    gameOver.setString("Game Over !");
    gameOver.setFillColor(sf::Color::Blue);
    gameOver.setCharacterSize(150);
    gameOver.setPosition(110, 200);
}

void Game::setAchievementString(sf::String string) {
    achievementText.setFont(font2);
    achievementText.setString(string);
    achievementText.setCharacterSize(40);
    achievementText.setFillColor(sf::Color::Red);
    achievementText.setStyle(sf::Text::Bold);
    achievementText.setPosition(windowSize.x, windowSize.y / 2);
}

void Game::render() {
    window.beginDraw();
    window.draw(background);
    if (!player.getDeath()) {
        window.draw(achievementText);
        if (speedPowerUp)
            window.draw(fireSprite);
        player.render(*window.getRenderWindow());
        for (auto &block : blocks)
            window.draw(*block);
        for (auto &enemy : enemies)
            window.draw(*enemy);
        for (auto &b : bullets)
            window.draw(b);
        for (auto &b : enemyBullets)
            window.draw(b);
        window.draw(text);
        window.draw(scoreText);
    } else {
        text.setCharacterSize(50);
        scoreText.setCharacterSize(50);
        text.setPosition(420, 450);
        scoreText.setPosition(595, 450);
        window.draw(gameOver);
        window.draw(text);
        window.draw(scoreText);
    }
    window.endDraw();
}

void Game::movePlayer() {
    player.setPlayerPosition(player.getPlayerPosition().x, player.getPlayerPosition().y + g);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
        player.setPlayerPosition(player.getPlayerPosition().x, player.getPlayerPosition().y - jump);
        if (isPowerUpOn)
            player.setPlayerTexture(puPlayerTexture2);
        else if (isDefectOn)
            player.setPlayerTexture(dePlayerTexture2);
        else
            player.setPlayerTexture(playerTexture2);
        playerTexture2.setSmooth(true);
    } else if (!sf::Keyboard::isKeyPressed((sf::Keyboard::Space))) {
        if (isPowerUpOn)
            player.setPlayerTexture(puPlayerTexture1);
        else if (isDefectOn)
            player.setPlayerTexture(dePlayerTexture1);
        else
            player.setPlayerTexture(playerTexture1);
        playerTexture1.setSmooth(true);
    }
    if (player.getPlayerPosition().y + player.getPlayerSize().y >= window.getWindowSize().y - levelGround)
        player.setPlayerPosition(player.getPlayerPosition().x,
                                 window.getWindowSize().y - player.getPlayerSize().y - levelGround);
    if (player.getPlayerPosition().y <= textSize)
        player.setPlayerPosition(player.getPlayerPosition().x, textSize);
}

void Game::shoot() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && playerClock.getElapsedTime().asSeconds() >= shootTime) {
        createBullet();
        shootSound.play();
        playerClock.restart();
    }
    moveBullet();
    if (enemyClock.getElapsedTime().asSeconds() >= shootTime * 1.5f) {
        createEnemyBullet();
        enemyClock.restart();
    }
    moveEnemyBullet();
}

void Game::createBullet() {
    bullet.setRadius(10);
    bullet.setFillColor(sf::Color::Black);
    bullet.setPosition(player.getPlayerPosition().x + player.getPlayerSize().x,
                       player.getPlayerPosition().y + player.getPlayerSize().y / 2);
    bullets.emplace_back(sf::CircleShape(bullet));
}

void Game::moveBullet() {
    for (int j = 0; j < bullets.size(); ++j)
        bullets[j].move(bulletSpeed, 0);
}

void Game::createEnemyBullet() {
    for (auto &j : enemies) {
        if (j->getCanShoot() && j->getPosition().x <= window.getWindowSize().x) {
            bullet.setRadius(10);
            bullet.setFillColor(sf::Color::Red);
            bullet.setPosition(j->getPosition().x, j->getPosition().y + j->getGlobalBounds().height / 2);
            enemyBullets.emplace_back(sf::CircleShape(bullet));
        }
    }
}

void Game::moveEnemyBullet() {
    for (int j = 0; j < enemyBullets.size(); ++j)
        enemyBullets[j].move(-speed.x * 1.5f, 0);
}

void Game::createObjects() {
    if (objectClock.getElapsedTime().asSeconds() >= creationRate) {
        if (counter % 5 == 0 && randomCreation() == 1) {
            std::unique_ptr<Enemy> enemy = factoryE.createEnemy(EnemyType::ShootingEnemy);
            if (randomCreation() % 2 != 0)
                enemy->setEnemySpeedY(speed.y);
            else
                enemy->setEnemySpeedY(-speed.y);
            enemy->setPosition(sf::Vector2f(2 * windowSize.x, randomPos()));
            enemies.emplace_back(move(enemy));
            isCreated = true;
            isEnemyCreated = true;
            objectClock.restart();
            counter++;
        }
        if (counter % 2 == 0 && randomCreation() == 1 && !isEnemyCreated) {
            std::unique_ptr<Enemy> enemy = factoryE.createEnemy(EnemyType::FlyingEnemy);
            if (randomCreation() % 2 != 0)
                enemy->setEnemySpeedY(speed.y);
            else
                enemy->setEnemySpeedY(-speed.y);
            enemy->setPosition(sf::Vector2f(2 * windowSize.x, randomPos()));
            enemies.emplace_back(move(enemy));
            isCreated = true;
            isEnemyCreated = true;
            objectClock.restart();
            counter++;
        }
        // se è già attivo un PowerUp non viene creato un PowerUpBlock
        if (counter % 7 == 0 && randomCreation() == 1 &&
            !isPowerUpOn && !isEnemyCreated && !isDefectOn && !speedPowerUp) {
            std::unique_ptr<Block> block = factoryB.createBlock(BlockType::PowerUpBlock);
            block->setPosition(sf::Vector2f(2 * windowSize.x, randomPos()));
            blocks.emplace_back(move(block));
            isCreated = true;
            objectClock.restart();
            counter++;
        }
        if (!isCreated) {
            std::unique_ptr<Block> block = factoryB.createBlock(BlockType::NormalBlock);
            block->setPosition(sf::Vector2f(2 * windowSize.x, randomPos()));
            blocks.emplace_back(move(block));
            objectClock.restart();
            counter++;
        }
        isCreated = false;
        isEnemyCreated = false;
    }
}

void Game::moveObject() {
    for (auto &i : blocks)
        i->move(-speed.x, 0);
    for (auto &j : enemies) {
        if (j->getPosition().y + j->getGlobalBounds().height >= window.getWindowSize().y - levelGround ||
            j->getPosition().y <= 0) {
            j->setEnemySpeedY(-j->getEnemySpeedY());
        }
        j->move(-speed.x, j->getEnemySpeedY());
    }
}

void Game::deleteObject() {
    // se un oggetto esce dallo schermo viene eliminato
    for (int i = 0; i < blocks.size(); ++i) {
        if (blocks[i]->getPosition().x + blocks[i]->getGlobalBounds().width < 0)
            blocks.erase(blocks.begin() + i);
    }
    for (int i = 0; i < enemies.size(); ++i) {
        if (enemies[i]->getPosition().x + enemies[i]->getGlobalBounds().width < 0)
            enemies.erase(enemies.begin() + i);
    }
    for (int i = 0; i < enemyBullets.size(); ++i) {
        if (enemyBullets[i].getPosition().x + enemyBullets[i].getGlobalBounds().width < 0)
            enemyBullets.erase(enemyBullets.begin() + i);
    }
    for (int i = 0; i < bullets.size(); ++i) {
        if (bullets[i].getPosition().x > windowSize.x)
            bullets.erase(bullets.begin() + i);
    }
}

void Game::collision() {
    for (int i = 0; i < blocks.size(); i++) {
        class NormalBlock *test = dynamic_cast<class NormalBlock *>(blocks[i].get());
        if (blocks[i]->getGlobalBounds().intersects(player.getBound())) {
            if (test != nullptr) {
                // se character ha PowerUp e interseca normalBlock perde il potenziamento
                if (isPowerUpOn) {
                    isPowerUpOn = false;
                    controlPowerUp.restart();
                } else if (controlPowerUp.getElapsedTime().asSeconds() >= tollerance) {
                    // se character non ha PowerUp e interseca normalBlock muore
                    player.gameOver(true);
                }
            }
            // se character interseca PowerUpBlock si attiva il potenziamento
            if (test == nullptr) {
                int random = randomPowerUp();
                if (random == 1) {
                    isDefectOn = true;
                    jump = -jump;
                    g = -g;
                    defectClock.restart();
                } else if (random == 0) {
                    // si attiva il terzo powerUp
                    speedPowerUp = true;
                    oldSpeed = speed;
                    fireSprite.setTexture(fireTexture1);
                    fireSprite.setPosition(player.getPlayerPosition() + player.getPlayerSize());
                    speed.x = 10.0f;
                    notify();
                    enemyBullets.clear();
                    speedClock.restart();
                } else {
                    // si attiva powerUp doppia vita
                    isPowerUpOn = true;
                }
                powerUpSound.play();
                score += 10;
                notify();
                blocks.erase(blocks.begin() + i);
            }
        }
        for (int j = 0; j < bullets.size(); j++) {
            // se bullet interseca un block viene eliminato
            if (blocks[i]->getGlobalBounds().intersects(bullets[j].getGlobalBounds()))
                bullets.erase(bullets.begin() + j);
        }
        for (int m = 0; m < enemyBullets.size(); m++) {
            // se enemyBullet interseca un block viene eliminato
            if (blocks[i]->getGlobalBounds().intersects(enemyBullets[m].getGlobalBounds()))
                enemyBullets.erase(enemyBullets.begin() + m);
        }
    }
    for (int k = 0; k < enemies.size(); k++) {
        if (enemies[k]->getGlobalBounds().intersects(player.getBound())) {
            // se character ha PowerUp e interseca enemy perde il potenziamento
            if (isPowerUpOn) {
                isPowerUpOn = false;
                controlPowerUp.restart();
            } else if (controlPowerUp.getElapsedTime().asSeconds() >= tollerance) {
                // se character non ha PowerUp e interseca enemy muore
                player.gameOver(true);
            }
        }
        // se bullet interseca un enemy viene eliminato enemy
        for (int l = 0; l < bullets.size(); l++) {
            if (bullets[l].getGlobalBounds().intersects(enemies[k]->getGlobalBounds())) {
                enemies.erase(enemies.begin() + k);
                bullets.erase(bullets.begin() + l);
                score += 5;
                killed++;
                enemyDeadSound.play();
                notify();
            }
        }
    }
    for (int z = 0; z < enemyBullets.size(); z++) {
        if (player.getBound().intersects(enemyBullets[z].getGlobalBounds())) {
            // se character ha PowerUp e interseca enemyBullet perde il potenziamento
            if (isPowerUpOn) {
                isPowerUpOn = false;
                controlPowerUp.restart();
            } else if (controlPowerUp.getElapsedTime().asSeconds() >= tollerance) {
                // se character non ha PowerUp e interseca enemyBullet muore
                player.gameOver(true);
            }
        }
    }
}

void Game::fireAnimation() {
    fireSprite.setPosition(player.getPlayerPosition().x - player.getPlayerSize().x / 2, player.getPlayerPosition().y);
    if (fireClock.getElapsedTime().asSeconds() >= 0.2f) {
        fireSprite.setTexture(fireTexture2);
        fireClock.restart();
    } else if (fireClock.getElapsedTime().asSeconds() >= 0.1) {
        fireSprite.setTexture(fireTexture1);
    }
}

int Game::randomPos() {
    return (rand() % maxY);
}

int Game::randomCreation() {
    return (rand() % 2);
}

int Game::randomPowerUp() {
    return (rand() % 3);
}

void Game::subscribe(Observer *o) {
    observers.push_back(o);
}

void Game::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Game::setScore(unsigned int score) {
    Game::score = score;
    notify();
}

void Game::setKilled(unsigned int killed) {
    Game::killed = killed;
    notify();
}

void Game::notify() {
    for (auto itr = std::begin(observers); itr != std::end(observers); itr++)
        (*itr)->update();
}

const float Game::getShootTime() { return shootTime; }

const float Game::getLevelGround() { return levelGround; }

const float Game::getBulletSpeed() { return bulletSpeed; }

const sf::Vector2f &Game::getSpeed() const { return speed; }

float Game::getCreationRate() const { return creationRate; }

int Game::getMaxY() const { return maxY; }

const std::vector<sf::CircleShape> &Game::getBullets() const { return bullets; }

int Game::getBlocksContainerSize() { return static_cast<int>(blocks.size()); };

int Game::getBulletsContainerSize() { return static_cast<int>(bullets.size()); };

int Game::getEnemiesContainerSize() { return static_cast<int>(enemies.size()); };

int Game::getEnemiesBulletsContainerSize() { return static_cast<int>(enemyBullets.size()); };

unsigned int Game::getScore() const { return score; }

unsigned int Game::getKilled() const { return killed; }

const float Game::getRateIncreaser() { return rateIncreaser; }

const float Game::getSpeedIncreaser() { return speedIncreaser; }

const sf::Vector2i &Game::getWindowSize() const { return windowSize; }

bool Game::getIsPowerUpOn() const { return isPowerUpOn; }