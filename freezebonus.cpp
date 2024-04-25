#include "freezebonus.h"
#include <QPainter>

FreezeBonus::FreezeBonus(QWidget *parent) : QWidget(parent) {}

void FreezeBonus::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(Qt::cyan);
    painter.drawEllipse(rect());
}
