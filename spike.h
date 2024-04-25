#ifndef SPIKE_H
#define SPIKE_H

#include <QWidget>

class Spike : public QWidget {
    Q_OBJECT
public:
    explicit Spike(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // SPIKE_H
