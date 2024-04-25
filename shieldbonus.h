#ifndef SHIELDBONUS_H
#define SHIELDBONUS_H

#include <QWidget>

class ShieldBonus : public QWidget {
    Q_OBJECT
public:
    explicit ShieldBonus(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // SHIELDBONUS_H
