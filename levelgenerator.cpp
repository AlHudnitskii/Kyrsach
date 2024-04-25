#include "levelgenerator.h"
#include <cstdlib>
#include <ctime>

Level::Level(int width, int height) {
    tiles.resize(height, std::vector<Tile>(width));
}

Level LevelGenerator::generateLevel(int width, int height) {
    Level level(width, height);
    srand(time(nullptr));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            level.tiles[y][x].type = getRandomTileType();
        }
    }

    return level;
}

TileType LevelGenerator::getRandomTileType() {
    double randomValue = (double)rand() / RAND_MAX;

    if (randomValue < 0.2) {
        return TileType::Wall;
    } else if (randomValue < 0.3) {
        return TileType::Coin;
    } else if (randomValue < 0.35) {
        return TileType::ShieldBonus;
    } else if (randomValue < 0.4) {
        return TileType::FreezeBonus;
    } else if (randomValue < 0.45) {
        return TileType::MultiplierBonus;
    } else if (randomValue < 0.6) {
        return TileType::Enemy;
    } else {
        return TileType::Empty;
    }
}
