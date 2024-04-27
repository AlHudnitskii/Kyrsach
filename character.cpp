#include "character.h"
#include <QPainter>
#include <QKeyEvent>

Character::Character(LevelGenerator *level, QWidget *parent)
    : QWidget(parent), m_level(level), m_coinsCollected(0), m_health(1) {}

void Character::move(int dx, int dy) {
    int newX = x() + dx;
    int newY = y() + dy;
    if (newX >= 0 && newX < width() && newY >= 0 && newY < height()) {
        if (m_level->getTile(newX, newY) != TileType::Wall) {
            move(newX, newY);
        }
    }
}

void Character::setLevel(LevelGenerator *level) {
    m_level = level;
}

int Character::getCoinsCollected() const {
    return m_coinsCollected;
}

int Character::getHealth() const {
    return m_health;
}

void Character::setHealth(int health) {
    m_health = health;
}

void Character::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::blue);
}

void Character::keyPressEvent(QKeyEvent *event) {

    switch (event->key()) {
    case Qt::Key_Left:
        move(-1, 0);
        break;
    case Qt::Key_Right:
        move(1, 0);
        break;
    case Qt::Key_Up:
        move(0, -1);
        break;
    case Qt::Key_Down:
        move(0, 1);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}


void Character::setLevel(LevelGenerator *level) {
    m_level = level;
}

int Character::getCoinsCollected() const {
    return m_coinsCollected;
}
