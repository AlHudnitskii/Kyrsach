#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QApplication>
#include <QWidget>
#include <QGridLayout>
#include "levelgenerator.h"
#include "TileWidget.h"

class GameManager : public QWidget {
    Q_OBJECT
public:
    explicit GameManager(QWidget *parent = nullptr);

private:
    void createLevel();
    void setupUI();
    void displayLevel();

    QGridLayout *m_layout;
    LevelGenerator m_level;
};

#endif // GAMEMANAGER_H
