#ifndef FREEZEBONUS_H
#define FREEZEBONUS_H

#include <QWidget>

class FreezeBonus : public QWidget {
    Q_OBJECT
public:
    explicit FreezeBonus(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // FREEZEBONUS_H
