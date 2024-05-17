#include "freezebonus.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

FreezeBonus::FreezeBonus(LevelGenerator *level, int x, int y, QWidget *parent)
    : QWidget(parent), m_level(level), m_x(x), m_y(y) {
    setFixedSize(50, 50);
}

void FreezeBonus::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::blue);
}

void FreezeBonus::mousePressEvent(QMouseEvent *event) {
    if (m_level && m_level->getTileType(m_x, m_y) == TileType::BonusFreeze) {

        emit enemiesFrozen();

        deleteLater();
    }
}
