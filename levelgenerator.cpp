#include "levelgenerator.h"

LevelGenerator::LevelGenerator(int width, int height) : m_width(width), m_height(height), m_numCoins(0) {
    m_tiles.resize(height);
    for (int y = 0; y < height; ++y) {
        m_tiles[y].resize(width, TileType::Empty);
    }
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

