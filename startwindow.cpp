#include "startwindow.h"
#include "ui_startwindow.h"

StartWindow::StartWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked, this, &StartWindow::onStartButtonClicked);
    connect(ui->closeButton, &QPushButton::clicked, this, &StartWindow::onCloseButtonClicked);
}

StartWindow::~StartWindow()
{
    delete ui;
}

void StartWindow::onStartButtonClicked()
{
    emit startGame();
}

void StartWindow::onCloseButtonClicked()
{
    emit closeApplication();
}
