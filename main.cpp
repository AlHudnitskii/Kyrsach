#include <QApplication>
#include "mainwindow.h"
#include "gamemanager.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    GameManager gameManager;
    QWidget window;
    window.show();

    return a.exec();
}
