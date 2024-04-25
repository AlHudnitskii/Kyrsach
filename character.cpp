#include "character.h"
#include <QPainter>

Character::Character(QWidget *parent) : QWidget(parent) {}

void Character::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.setBrush(Qt::blue);
    painter.drawEllipse(rect());
}
