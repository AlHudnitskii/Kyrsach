#ifndef LEVELGENERATOR_H
#define LEVELGENERATOR_H

#include <vector>

enum class TileType { Wall, Coin, ShieldBonus, FreezeBonus, MultiplierBonus, Enemy, Empty };

struct Tile {
    TileType type;
};

class Level {
public:
    std::vector<std::vector<Tile>> tiles;

    Level(int width, int height);
};

class LevelGenerator {
public:
    static Level generateLevel(int width, int height);

private:
    static TileType getRandomTileType();
};

#endif // LEVELGENERATOR_H
