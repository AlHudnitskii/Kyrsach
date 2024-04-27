#ifndef CHARACTER_H
#define CHARACTER_H

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

signals:
    void coinsCollectedChanged(int count);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    LevelGenerator *m_level;
    int m_coinsCollected; // монеты
    int m_health; // здоровье
};

#endif // CHARACTER_H
