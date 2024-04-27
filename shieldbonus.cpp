#include "shieldbonus.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "character.h"

ShieldBonus::ShieldBonus(LevelGenerator *level, int x, int y, QWidget *parent)
    : QWidget(parent), m_level(level), m_x(x), m_y(y) {
    setFixedSize(50, 50);
}

void ShieldBonus::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::green);
}

void ShieldBonus::mousePressEvent(QMouseEvent *event) {
    if (m_level && m_level->getTile(m_x, m_y) == TileType::ShieldBonus) {

        int newHealth = character->getHealth() + 1;
        character->setHealth(newHealth);

        emit healthIncreased(newHealth);

        deleteLater();
    }
}
