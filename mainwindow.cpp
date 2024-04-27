#include "mainwindow.h"
#include "TileWidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), centralWidget(new QWidget), layout(new QGridLayout), level(LevelGenerator::LevelGenerator(10, 10)) {
    setCentralWidget(centralWidget);
    centralWidget->setLayout(layout);

    createLevel();
    setWindowState(Qt::WindowFullScreen);
}

void MainWindow::createLevel() {
    const std::vector<std::vector<Tile>>& tiles = level.getTiles();
    for (int y = 0; y < level.tiles.size(); ++y) {
        for (int x = 0; x < level.tiles[y].size(); ++x) {
            TileWidget *tileWidget = new TileWidget(centralWidget);
            tileWidget->setType(level.tiles[y][x].type);
            layout->addWidget(tileWidget, y, x);
        }
    }
}
