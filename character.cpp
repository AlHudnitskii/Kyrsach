#include "character.h"
#include <QPainter>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsItem>
#include <QTimer>

QMap<TileType, QColor> tileColorMap = {
    {TileType::Empty, Qt::white},
    {TileType::Wall, Qt::black},
    {TileType::Character, Qt::gray},
    {TileType::Goal, Qt::darkGreen}
};

Character::Character(LevelGenerator *levelGenerator,QGraphicsScene *scene, QWidget *parent)
    : QWidget(parent), m_level(levelGenerator), m_coinsCollected(0), m_health(1), m_x(30), m_y(30) {

    m_graphicsItem = new QGraphicsRectItem();
    scene->addItem(m_graphicsItem);

    setFocusPolicy(Qt::StrongFocus);
    setFocus();

    m_timer.start();
}


void Character::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    // Рисование персонажа (пример)
    painter.setBrush(QBrush(tileColorMap[TileType::Character]));
    painter.drawRect(m_x * 30, m_y * 30, 30, 30);
}

void Character::move(int dx, int dy) {
    qDebug() << "Move method called with dx:" << dx << "dy:" << dy;
    int newX = m_x + dx;
    int newY = m_y + dy;

    TileType tileType = m_level->getTileType(newX, newY);
    if (tileType != TileType::Wall) {
        qDebug() << "Moving character";


        //m_graphicsItem->setRect(m_x * 30, m_y * 30, 30, 30);
        //m_graphicsItem->setBrush(QBrush(Qt::gray));


        m_level->setTileType(m_y, m_x, TileType::Empty);
        scene->addRect(m_x * 30, m_y * 30, 30, 30, QPen(), QBrush(tileColorMap[TileType::Empty]));

        // Обновление координат
        m_x = newX;
        m_y = newY;

        // Установка нового типа и цвета для новой клетки
        m_level->setTileType(m_y, m_x, TileType::Character);
        scene->addRect(m_x * 30, m_y * 30, 30, 30, QPen(), QBrush(tileColorMap[TileType::Character]));

        // Обновление координат
        m_x = newX;
        m_y = newY;

        emit moved();
    }
    checkGoal();
    m_graphicsItem->update(); // Обновление QGraphicsItem
}

void Character::setX(int x) {
    m_x = x;
}

void Character::setY(int y) {
    m_y = y;
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

void Character::keyPressEvent(QKeyEvent *event) {
    qDebug() << "keyPressEvent" << event->key();
    if (event->key() == Qt::Key_W) {
        move(0, -1);
    } else if (event->key() == Qt::Key_S) {
        move(0, 1);
    } else if (event->key() == Qt::Key_A) {
        move(-1, 0);
    } else if (event->key() == Qt::Key_D) {
        move(1, 0);
    } else {
        QWidget::keyPressEvent(event);
    }
}

void Character::checkGoal() {
    qDebug() << "CheckGoal";
    TileType cellType = m_level->tileTypeAt(m_x, m_y);
    if (cellType == TileType::Goal) {
        qDebug() << "Goal is check";
        QMessageBox messageBox;
        messageBox.setText("Goal reached!");
        qint64 elapsedTime = m_timer.elapsed();
        QString infoText = QString("Elapsed time: %1 milliseconds\nReceived coins: %2")
                               .arg(elapsedTime)
                               .arg(m_coinsCollected);
        messageBox.setInformativeText(infoText);
        messageBox.exec();
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
