#include "gamemanager.h"

GameManager::GameManager(QWidget *parent) : QWidget(parent) {
    createLevel();
    setupUI();
    displayLevel();
}

void GameManager::createLevel() {
    m_level = LevelGenerator::generateLevel(10, 10);
}

void GameManager::setupUI() {
    m_layout = new QGridLayout(this);

    for (int y = 0; y < m_level.tiles.size(); ++y) {
        for (int x = 0; x < m_level.tiles[y].size(); ++x) {
            TileWidget *tileWidget = new TileWidget(this);
            tileWidget->setType(m_level.tiles[y][x].type);
            m_layout->addWidget(tileWidget, y, x);
        }
    }

    setLayout(m_layout);
}

void GameManager::displayLevel() {
    show();
}
