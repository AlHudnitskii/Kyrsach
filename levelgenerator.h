#ifndef LEVELGENERATOR_H
#define LEVELGENERATOR_H

#include <QVector>
#include <utility>

enum class TileType {
    Wall,
    Coin,
    ShieldBonus,
    FreezeBonus,
    MultiplierBonus,
    Enemy,
    Empty
};

class LevelGenerator {
public:
    explicit LevelGenerator(int width, int height);
    int getWidth() const;
    int getHeight() const;
    TileType getTileType(int x, int y) const;
    void setTileType(int x, int y, TileType type);
    int getNumCoins() const;
    void incrementCoins();

private:
    int m_width;
    int m_height;
    QVector<QVector<TileType>> m_tiles;
    int m_numCoins;
};

#endif // LEVELGENERATOR_H

