#include "coin.h"
#include <QPainter>

Coin::Coin(QWidget *parent) : QWidget(parent) {}

void Coin::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(Qt::yellow);
    painter.drawEllipse(rect());
}
