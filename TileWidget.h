#ifndef TILEWIDGET_H
#define TILEWIDGET_H

#include <QWidget>
#include "levelgenerator.h"

class TileWidget : public QWidget {
    Q_OBJECT
public:
    explicit TileWidget(QWidget *parent = nullptr);

    void setType(TileType type);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    TileType m_type;
};

#endif // TILEWIDGET_H
