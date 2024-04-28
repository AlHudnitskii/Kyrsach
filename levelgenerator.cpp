#include "levelgenerator.h"
#include <cstdlib>
#include <ctime>

LevelGenerator::LevelGenerator(int width, int height) : m_width(width), m_height(height), m_numCoins(0) {
    srand(time(nullptr));

    LevelGenerator level(width, height);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
                level.setTile(x, y, TileType::Wall);
            }
        }
    }

    placeBonus(level, TileType::ShieldBonus);
    placeBonus(level, TileType::FreezeBonus);
    placeBonus(level, TileType::CoinBonus);

    placeEntities(level, Type::Enemy, 3);

    placeSpikes(level, 3, 3, 2);

    level.setTile(1, 1, TyleType::CharacterSpawn);

    level.setTile(width - 2, height - 2, TyleType::Goal);
}

int LevelGenerator::getWidth() const {
    return m_width;
}

int LevelGenerator::getHeight() const {
    return m_height;
}

TileType LevelGenerator::getTileType(int x, int y) const {
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        return m_tiles[y][x];
    }
    return TileType::Empty;
}

void LevelGenerator::setTileType(int x, int y, TileType type) {
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        m_tiles[y][x] = type;
        if (type == TileType::Coin) {
            m_numCoins++;
        }
    }
}

int LevelGenerator::getNumCoins() const {
    return m_numCoins;
}

void LevelGenerator::incrementCoins() {
    m_numCoins++;
}

