#ifndef CHARACTER_H
#define CHARACTER_H

#include <QKeyEvent>
#include <QWidget>
#include "levelgenerator.h"
#include <QElapsedTimer>
#include <QGraphicsItem>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>
#include <QGraphicsRectItem>

class Character : public QWidget {
    Q_OBJECT
public:
    Character(LevelGenerator *levelgenerator, QGraphicsScene *scene,  QWidget *parent = nullptr);

    //void move(int dx, int dy);
    void setLevel(LevelGenerator *level);

    int getCoinsCollected() const;
    void setCoinsCollected(int newCoins);

    int getHealth() const;
    void setHealth(int health);

    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void checkGoal();
    void die();

    QColor getTileColor(TileType tileType);

signals:
    void coinsCollectedChanged(int count);
    void moved();


private slots:
    void move(int dx, int dy);

protected:
    void paintEvent(QPaintEvent *event) override;
    void paintTile(QPainter &painter, int x, int y);
    void keyPressEvent(QKeyEvent *event) override;

private:
    LevelGenerator *m_level;

    int m_coinsCollected;
    int m_health;

    QElapsedTimer m_timer;
    QGraphicsRectItem *m_graphicsItem;
    QGraphicsScene* scene;

    int m_x;
    int m_y;
};

#endif // CHARACTER_H
