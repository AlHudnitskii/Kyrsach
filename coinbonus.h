#ifndef COINBONUS_H
#define COINBONUS_H

#include <QWidget>
#include "enemy.h"
#include "levelgenerator.h"

class CoinBonus : public QWidget {
    Q_OBJECT
public:
    CoinBonus(LevelGenerator *level, int x, int y, QWidget *parent = nullptr);

signals:
    void multiplyCoins();

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    LevelGenerator *m_level;
    int m_x;
    int m_y;
};

#endif // COINBONUS_H
