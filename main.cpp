#include <QApplication>
#include <QGridLayout>
#include "levelgenerator.h"
#include "TileWidget.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QWidget window;
    QGridLayout *layout = new QGridLayout(&window);

    Level level = LevelGenerator::generateLevel(10, 10);

    for (int y = 0; y < level.tiles.size(); ++y) {
        for (int x = 0; x < level.tiles[y].size(); ++x) {
            TileWidget *tileWidget = new TileWidget(&window);
            tileWidget->setType(level.tiles[y][x].type);
            layout->addWidget(tileWidget, y, x);
        }
    }

    window.setLayout(layout);
    window.show();

    return a.exec();
}
