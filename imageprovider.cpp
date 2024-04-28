#include "imageprovider.h"

QMap<TileType, QPixmap> ImageProvider::m_imageCache;

QPixmap ImageProvider::getImage(TileType tileType) {
    if (!m_imageCache.contains(tileType)) {
        QPixmap image;
        switch (tileType) {
        case TileType::Empty:
            image.load(":/images/empty.png");
            break;
        case TileType::Wall:
            image.load(":/images/wall.png");
            break;
        case TileType::Character:
            image.load(":/images/character.png");
            break;
        case TileType::Enemy:
            image.load(":/images/enemy.png");
            break;
        case TileType::BonusShield:
            image.load(":/images/bonus_shield.png");
            break;
        case TileType::BonusFreeze:
            image.load(":/images/bonus_freeze.png");
            break;
        case TileType::BonusCoin:
            image.load(":/images/bonus_coin.png");
            break;
        case TileType::Spike:
            image.load(":/images/spike.png");
            break;
        case TileType::Goal:
            image.load(":/images/goal.png");
            break;
        }
        m_imageCache.insert(tileType, image);
    }
    return m_imageCache.value(tileType);
}
