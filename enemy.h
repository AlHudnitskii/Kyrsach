#ifndef ENEMY_H
#define ENEMY_H

#include <QWidget>

class Enemy : public QWidget {
    Q_OBJECT
public:
    explicit Enemy(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // ENEMY_H
