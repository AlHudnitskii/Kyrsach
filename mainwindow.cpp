#include "mainwindow.h"
#include "TileWidget.h"
#include "levelgenerator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), centralWidget(new QWidget), layout(new QGridLayout), level(60, 30)
{
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);

    createLevel();
    setWindowState(Qt::WindowFullScreen);
}

MainWindow::~MainWindow()
{
    delete layout;
    delete centralWidget;
}

void MainWindow::createLevel() {
    const int width = level.getWidth();
    const int height = level.getHeight();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            TileWidget *tileWidget = new TileWidget(centralWidget);
            tileWidget->setType(level.getTileType(x, y));
            layout->addWidget(tileWidget, y, x);
        }
    }
}
