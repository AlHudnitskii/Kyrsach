#include "shieldbonus.h"
#include <QPainter>

ShieldBonus::ShieldBonus(QWidget *parent) : QWidget(parent) {}

void ShieldBonus::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(Qt::green);
    painter.drawRect(rect());
}
