#include "character.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>

Character::Character(LevelGenerator *levelgenerator, QWidget *parent)
    : QWidget(parent), m_level(levelgenerator), m_coinsCollected(0), m_health(1) {
    m_timer.start();
}

QRectF Character::boundingRect() const {
    return QRectF(0, 0, 20, 20);
}

void Character::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);

    painter->setBrush(Qt::gray);
    painter->drawRect(0, 0, 20, 20);
}

void Character::move(int dx, int dy) {

    int currentX = getX();
    int currentY = getY();

    int newX = currentX + dx;
    int newY = currentY + dy;

    if (newX >= 0 && newX < m_level->getWidth() && newY >= 0 && newY < m_level->getHeight()) {
        if (m_level->getTileType(newX, newY) != TileType::Wall) {
            setX(newX);
            setY(newY);
            setPos(m_x * 20, m_y * 20);
            checkGoal();
            update();
        }
    }

}

void Character::setLevel(LevelGenerator *level) {
    m_level = level;
}

int Character::getCoinsCollected() const {
    return m_coinsCollected;
}

void Character::setCoinsCollected(int newCoins)
{
    m_coinsCollected = newCoins;
}

int Character::getHealth() const {
    return m_health;
}

void Character::setHealth(int health) {
    m_health = health;
}

int Character::getX() const {
    return m_x;
}

int Character::getY() const {
    return m_y;
}

void Character::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);
}

void Character::keyPressEvent(QKeyEvent *event) {

    switch (event->key()) {
    case Qt::Key_A:
        move(-1, 0);
        break;
    case Qt::Key_D:
        move(1, 0);
        break;
    case Qt::Key_W:
        move(0, -1);
        break;
    case Qt::Key_S:
        move(0, 1);
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void Character::checkGoal() {
    TileType cellType = m_level->tileTypeAt(m_x, m_y);
    if (cellType == TileType::Goal) {
        qDebug() << "Goal reached!";
        qint64 elapsedTime = m_timer.elapsed();
        qDebug() << "Elapsed time: " << elapsedTime << "milliseconds";
        qDebug() << "Recives coins: " << m_coinsCollected << "coins";
    }
}

void Character::die() {
    m_timer.invalidate();

    QMessageBox messageBox;
    messageBox.setText("Game Over!");
    messageBox.setInformativeText("You died!");
    messageBox.exec();

    close();
}
