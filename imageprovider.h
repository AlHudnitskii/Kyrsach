#ifndef IMAGEPROVIDER_H
#define IMAGEPROVIDER_H

#include <QPixmap>
#include <QMap>

enum class TileType {
    Empty,
    Wall,
    Character,
    Enemy,
    BonusShield,
    BonusFreeze,
    BonusCoin,
    Spike,
    Goal
};

class ImageProvider {
public:
    static QPixmap getImage(TileType tileType);

private:
    static QMap<TileType, QPixmap> m_imageCache;
};

#endif // IMAGEPROVIDER_H
