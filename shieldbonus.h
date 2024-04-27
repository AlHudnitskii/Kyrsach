#ifndef SHIELDBONUS_H
#define SHIELDBONUS_H

#include "levelgenerator.h""
#include <QWidget>

class ShieldBonus : public QWidget {
    Q_OBJECT
public:
    ShieldBonus(LevelGenerator *level, int x, int y, QWidget *parent = nullptr);

signals:
    void healthIncreased(int newHealth);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    LevelGenerator *m_level;
    int m_x;
    int m_y;
};

#endif // SHIELDBONUS_H
