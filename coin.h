#ifndef COIN_H
#define COIN_H

#include <QWidget>

class Coin : public QWidget {
    Q_OBJECT
public:
    explicit Coin(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // COIN_H
