#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QDebug>

#include "Box.h"
#include "Mario.h"
#include <iostream>


int main(int argc, char *argv[]) {
    QApplication application(argc, argv);

    QGraphicsScene *scene = new QGraphicsScene();

    // Add box
    Box * box = new Box(); // Nous utilisons notre nouvelle classe Box
    box->setRect(100, -100, 100, 100);

    // Nous devons faire en sorte que Box reçoive les événements clavier
    box->setFlag(QGraphicsItem::ItemIsFocusable);
    box->setFocus();

    scene->addItem(box);

    // Add Mario
    Mario *mario = new Mario(scene->width() /2, scene->height() /2);
    scene->addItem(mario);


    // Visualize the scene
    QGraphicsView *view = new QGraphicsView(scene);
    view->showMaximized();

    // Enable movement
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();

    return application.exec();
}
