#include "coinbonus.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

CoinBonus::CoinBonus(LevelGenerator *level, int x, int y, QWidget *parent)
    : QWidget(parent), m_level(level), m_x(x), m_y(y) {
    setFixedSize(50, 50);
}

void CoinBonus::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::blue);
}

void CoinBonus::mousePressEvent(QMouseEvent *event) {
    if (m_level && m_level->getTile(m_x, m_y) == TleType::FreezeBonus) {

        emit multiply();

        deleteLater();
    }
}
