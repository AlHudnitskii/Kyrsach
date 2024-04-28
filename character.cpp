#include "character.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>

Character::Character(LevelGenerator *level, QWidget *parent)
    : QWidget(parent), m_level(level), m_coinsCollected(0), m_health(1) {}

void Character::move(int dx, int dy) {

    int currentX = getX();
    int currentY = getY();

    int newX = currentX + dx;
    int newY = currentY + dy;

    if (newX >= 0 && newX < m_level->getWidth() && newY >= 0 && newY < m_level->getHeight()) {
        if (m_level->getTile(newX, newY) != TileType::Wall) {
            setX(newX);
            setY(newY);
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

void Character::checkGoal() {
    TyleType cellType = m_level->getTile(m_x, m_y);

    if (cellType == TyleType::Goal) {
        m_timer->stop();

        int coinsEarned = m_coinsCollected * m_health * (500 - m_elapsedTime) / 500;

        ResultWindow *resultWindow = new ResultWindow(coinsEarned);
        resultWindow->show();

        close();
    }
}

void Character::die() {
    m_timer->stop();

    QMessageBox messageBox;
    messageBox.setText("Game Over!");
    messageBox.setInformativeText("You died!");
    messageBox.exec();

    close();
}
