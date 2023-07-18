//
// Created by robin on 17/07/23.
//

#include <QKeyEvent>

#include "Mario.h"

Mario::Mario(double scene_height, double scene_width) :  GameObject(scene_height, scene_width) {

    // Assign position
    this->setPrevDirection(DOWN);

    // Assign sprite
    this->setPixmap(this->getSheet().copy(0 * this->getTileWidth(), 4 * this->getTileHeight(),
                                          this->getTileWidth(), this->getTileHeight()));

    setPos(scene_width /2, scene_height /2);

    // Enable key events
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

Direction Mario::getPrevDirection() const {
    return prevDirection;
}

void Mario::setPrevDirection(Direction prevDirection) {
    Mario::prevDirection = prevDirection;
}

void Mario::keyPressEvent(QKeyEvent *event)  {
    if (event->key() == Qt::Key_Left) {
        setPos(x()-10, y());
        if (this->prevDirection != LEFT) {
            this->setPrevDirection(LEFT);
            this->setPixmap(this->getSheet().copy(3 * this->getTileWidth(), 6 * this->getTileHeight(),
                                                  this->getTileWidth(), this->getTileHeight()));
        }
    }
    else if (event->key() == Qt::Key_Right) {
        setPos(x()+10, y());
        if (this->prevDirection != RIGHT) {
            this->setPrevDirection(RIGHT);
            this->setPixmap(this->getSheet().copy(0 * this->getTileWidth() , 6 * this->getTileHeight(),
                                                  this->getTileWidth(), this->getTileHeight()));
        }
    }
    else if (event->key() == Qt::Key_Up) {
        setPos(x(), y()-10);
        if (this->prevDirection != UP) {
            this->setPrevDirection(UP);
            this->setPixmap(this->getSheet().copy(3 * this->getTileWidth(), 4 * this->getTileHeight(),
                                                  this->getTileWidth(), this->getTileHeight()));
        }
    }
    else if (event->key() == Qt::Key_Down) {
        setPos(x(), y()+10);
        if (this->prevDirection != DOWN) {
            this->setPrevDirection(DOWN);
            this->setPixmap(this->getSheet().copy(0 * this->getTileWidth(), 4 * this->getTileHeight(),
                                                  this->getTileWidth(), this->getTileHeight()));
        }
    }
}
