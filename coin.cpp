#include "coin.h"
#include "character.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

Coin::Coin(LevelGenerator *level, int x, int y, QWidget *parent)
    : QWidget(parent), m_level(level), m_x(x), m_y(y) {
    setFixedSize(50, 50);
}

void Coin::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::yellow);
}

void Coin::mousePressEvent(QMouseEvent *event, Character* character ) {
    if (m_level && m_level->getTileType(m_x, m_y) == TileType::Coin) {
        int newCoins = character->getCoinsCollected() + 5;
        character->setCoinsCollected(newCoins);

        emit coinsChanged(newCoins);

        deleteLater();
    }
}
