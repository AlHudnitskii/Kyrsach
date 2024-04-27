#include "spike.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include "levelgenerator.h"

Spike::Spike(LevelGenerator *level, int x, int y, QWidget *parent)
    : QWidget(parent), m_level(level), m_x(x), m_y(y) {
    setFixedSize(50, 50);
}

void Spike::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::red);
}

void Spike::mousePressEvent(QMouseEvent *event) {
    if (m_level && m_level->getTile(m_x, m_y) == TyleType::Spike) {
        int newHealth = character->getHealth() - 1;
        character->setHealth(newHealth);

        if (newHealth <= 0) {
            // умер типо, дописать
        }
    }
}
