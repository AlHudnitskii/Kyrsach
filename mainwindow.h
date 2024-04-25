#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include "levelgenerator.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);

private:
    void createLevel();

    QWidget *centralWidget;
    QGridLayout *layout;
    Level level;
};

#endif // MAINWINDOW_H
