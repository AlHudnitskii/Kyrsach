#ifndef LEVELGENERATOR_H
#define LEVELGENERATOR_H

#include <QVector>
#include <utility>

enum class TileType {
    Empty,
    Wall,
    Character,
    Enemy,
    BonusShield,
    BonusFreeze,
    BonusCoin,
    Spike,
    Goal,
    Coin,
    OutOfBounds
};

struct Tile {
    TileType type;
};

class LevelGenerator {
public:
    LevelGenerator(int width, int height);
    void generateMaze(int startX, int startY);
    QVector<QVector<TileType>> generateLevel() const;
    int getWidth() const;
    int getHeight() const;
    TileType getTileType(int x, int y) const;
    void setTileType(int x, int y, TileType type);
    int getNumCoins() const;
    void incrementCoins();
    TileType tileTypeAt(int x, int y) const;
    bool isAreaFree(int startX, int startY, int width, int height) const;
    void placeBonus(TileType bonusType);
    void placeEntities(TileType entityType, int count);
    void placeSpikes(int spikeCount1, int spikeCount2, int spikeCount3);

private:
    int m_width;
    int m_height;
    QVector<QVector<TileType>> m_tiles;
    int m_numCoins;
};

#endif // LEVELGENERATOR_H

