#ifndef LEVELGENERATOR_H
#define LEVELGENERATOR_H

#include <QVector>
#include <utility>

enum class TileType {
    Wall,
    Coin,
    ShieldBonus,
    FreezeBonus,
    CoinBonus,
    Enemy,
    CharacterSpawn,
    Goal,
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

    static void placeBonus(LevelGenerator &level, TileType bonusType);
    static void placeEntities(LevelGenerator &level, TileType entityType, int count);
    static void placeSpikes(LevelGenerator &level, int spikeCount1, int spikeCount2, int spikeCount3);
    static void placeSpikesNearWall(LevelGenerator &level, int wallX, int wallY, int spikeCount);
};

#endif // LEVELGENERATOR_H

