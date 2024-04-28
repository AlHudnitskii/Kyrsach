#include "enemy.h"
#include <QPainter>
#include <QTimer>

Enemy::Enemy(LevelGenerator *level, int startX, int startY) : QWidget(), m_level(level), m_x(startX), m_y(startY), m_direction(1) {
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(move()));
}

void Enemy::startMoving() {
    m_timer->start(500);
}

void Enemy::move() {
    if (m_level->getTile(m_x + m_direction, m_y) == TileType::Wall) {
        m_direction *= -1;
    } else {
        m_x += m_direction;
    }
}

void Enemy::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(Qt::red);
    painter.drawEllipse(rect());
}
