#ifndef CHARACTER_H
#define CHARACTER_H

#include <QKeyEvent>
#include <QWidget>
#include "levelgenerator.h"
#include <QElapsedTimer>
#include <QGraphicsItem>

class Character : public QWidget {
    Q_OBJECT
public:
    Character(LevelGenerator *levelgenerator, QWidget *parent = nullptr);
    void move(int dx, int dy);
    void setLevel(LevelGenerator *level);
    int getCoinsCollected() const;
    void setCoinsCollected(int newCoins);
    int getHealth() const;
    void setHealth(int health);
    int getX() const;
    int getY() const;
    void setX(int x) { m_x = x; }
    void setY(int y) { m_y = y; }
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void checkGoal();
    void die();

signals:
    void coinsCollectedChanged(int count);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    LevelGenerator *m_level;
    int m_coinsCollected;
    int m_health;
    QElapsedTimer m_timer;
    int m_x;
    int m_y;
};

#endif // CHARACTER_H
