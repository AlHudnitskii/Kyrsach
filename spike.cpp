#include "spike.h"
#include <QPainter>

Spike::Spike(QWidget *parent) : QWidget(parent) {}

void Spike::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setPen(Qt::red);
    painter.drawLine(rect().topLeft(), rect().bottomRight());
    painter.drawLine(rect().topRight(), rect().bottomLeft());
}
