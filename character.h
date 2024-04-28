#ifndef CHARACTER_H
#define CHARACTER_H

#include <QKeyEvent>
#include <QWidget>
#include "levelgenerator.h"


class Character : public QWidget {
    Q_OBJECT
public:
    Character(LevelGenerator *level);
    void move(int dx, int dy);
    void setLevel(LevelGenerator *level);
    int getCoinsCollected() const;
    void getHealth() const;
    void setHealth(int health);
    int getX() const;
    int getY() const;

public slots:
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
    int m_elapsedTime;
};

#endif // CHARACTER_H
