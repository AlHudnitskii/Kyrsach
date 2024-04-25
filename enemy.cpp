#include "enemy.h"
#include <QPainter>

Enemy::Enemy(QWidget *parent) : QWidget(parent) {}

void Enemy::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(Qt::red);
    painter.drawEllipse(rect());
}
