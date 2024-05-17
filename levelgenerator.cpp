#include "levelgenerator.h"
#include <cstdlib>
#include <ctime>
#include <QStack>

LevelGenerator::LevelGenerator(int width, int height) : m_width(width), m_height(height), m_numCoins(0) {
    srand(time(nullptr));

    // Set the border walls
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (x == 0 || y == 0 || x == width - 1 || y == height - 1) {
                setTileType(x, y, TileType::Wall);
            }
        }
    }

    generateMaze(1, 1);
    placeBonus(TileType::BonusShield);
    placeBonus(TileType::BonusFreeze);
    placeBonus(TileType::BonusCoin);
    placeBonus(TileType::BonusShield);
    placeBonus(TileType::BonusFreeze);
    placeBonus(TileType::BonusCoin);
    placeBonus(TileType::BonusShield);
    placeBonus(TileType::BonusFreeze);
    placeBonus(TileType::BonusCoin);
    placeBonus(TileType::BonusShield);
    placeBonus(TileType::BonusFreeze);
    placeBonus(TileType::BonusCoin);

    placeEntities(TileType::Enemy, 10);



    placeSpikes(3, 3, 2);

    m_tiles[1][1] = TileType::Character;
    m_tiles[height - 2][width - 2] = TileType::Goal;

}

void LevelGenerator::generateMaze(int startX, int startY) {
    for (int y = 0; y < m_height; ++y) {
        for (int x = 0; x < m_width; ++x) {
            m_tiles[y][x] = TileType::Wall;
        }
    }

    QStack<std::pair<int, int>> cellStack;
    cellStack.push({startX, startY});
    setTileType(startX, startY, TileType::Empty);

    while (!cellStack.empty()) {
        auto [x, y] = cellStack.top();
        cellStack.pop();

        int directions[4][2] = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};
        std::random_shuffle(std::begin(directions), std::end(directions));

        for (auto& direction : directions) {
            int nx = x + direction[0];
            int ny = y + direction[1];

            if (nx > 0 && ny > 0 && nx < m_width - 1 && ny < m_height - 1) {
                if (m_tiles[ny][nx] == TileType::Wall) {
                    setTileType(nx, ny, TileType::Empty);
                    setTileType(x + direction[0] / 2, y + direction[1] / 2, TileType::Empty);
                    cellStack.push({nx, ny});
                }
            }
        }
    }

    int currentX = startX;
    int currentY = startY;
    while (currentX < m_width - 2 || currentY < m_height - 2) {
        if (currentX < m_width - 2) {
            currentX++;
            setTileType(currentX, currentY, TileType::Empty);
        }
        if (currentY < m_height - 2) {
            currentY++;
            setTileType(currentX, currentY, TileType::Empty);
        }
    }

    int coinsPlaced = 0;
    while (coinsPlaced < 100) {
        int x = rand() % m_width;
        int y = rand() % m_height;

        if (m_tiles[y][x] == TileType::Empty) {
            setTileType(x, y, TileType::Coin);
            coinsPlaced++;
        }
    }

}

QVector<QVector<TileType>> LevelGenerator::generateLevel() const {
    return m_tiles;
}

void LevelGenerator::placeBonus(TileType bonusType) {
    while (true) {
        int x = rand() % m_width;
        int y = rand() % m_height;

        if (m_tiles[y][x] == TileType::Empty) {
            m_tiles[y][x] = bonusType;
            break;
        }
    }
}

void LevelGenerator::placeEntities(TileType entityType, int numEntities) {
    for (int i = 0; i < numEntities; ++i) {
        int x, y;
        do {
            x = rand() % m_width;
            y = rand() % m_height;
        } while (m_tiles[y][x] != TileType::Empty);

        m_tiles[y][x] = entityType;
    }
}

void LevelGenerator::placeSpikes(int numSpikes, int width, int height) {
    for (int i = 0; i < numSpikes; ++i) {
        int x, y;
        do {
            x = rand() % (m_width - width);
            y = rand() % (m_height - height);
        } while (!isAreaFree(x, y, width, height));

        for (int row = y; row < y + height; ++row) {
            for (int col = x; col < x + width; ++col) {
                m_tiles[row][col] = TileType::Spike;
            }
        }
    }
}

bool LevelGenerator::isAreaFree(int startX, int startY, int width, int height) const {
    for (int row = startY; row < startY + height; ++row) {
        for (int col = startX; col < startX + width; ++col) {
            if (m_tiles[row][col] != TileType::Empty) {
                return false;
            }
        }
    }
    return true;
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
    } else {
        return TileType::Empty;
    }
}

void LevelGenerator::setTileType(int x, int y, TileType type) {
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        if (static_cast<int>(m_tiles.size()) <= y)
            m_tiles.resize(y + 1);

        if (static_cast<int>(m_tiles[y].size()) <= x)
            m_tiles[y].resize(x + 1);

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

TileType LevelGenerator::tileTypeAt(int x, int y) const {
    if (x >= 0 && x < m_width && y >= 0 && y < m_height) {
        return m_tiles[y][x];
    } else {
        return TileType::OutOfBounds;
    }
}
