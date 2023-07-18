#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>

#include "Box.h"
#include "Utils.h"
#include <iostream>


int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();

    bool map = Utils::readMap("../map.txt", scene);
    if (!map) {
        return -1;
    }

    // Add box
/*    Box * box = new Box(); // Nous utilisons notre nouvelle classe Box
    box->setRect(100, -100, 100, 100);

    scene->addItem(box);*/

    // Visualize the scene
    QGraphicsView *view = new QGraphicsView(scene);
    view->showMaximized();

    // Enable movement
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    int exec = application.exec();

    delete scene;

    return exec;
}
