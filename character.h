#ifndef CHARACTER_H
#define CHARACTER_H

#include <QWidget>

class Character : public QWidget {
    Q_OBJECT
public:
    explicit Character(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // CHARACTER_H
