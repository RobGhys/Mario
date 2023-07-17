//
// Created by robin on 17/07/23.
//

#include <QKeyEvent>

#include "Mario.h"

Mario::Mario(double scene_height, double scene_width) :  QGraphicsPixmapItem() {

    // Link sprites
    //QPixmap sheet("../resources/Tilesheet/sokoban_tilesheet.png");
    this->setSheet(QPixmap("../resources/Tilesheet/sokoban_tilesheet.png"));
    if (this->sheet.isNull()) {
        qDebug() << "Did not find image";
    } else {
        qDebug() << "Loading Mario image";
    }

    // Assign position
    this->setPrevDirection(DOWN);
    this->setTileHeight(8, sheet);
    this->setTileWidth(13, sheet);

    // Assign sprite
    this->setPixmap(this->getSheet().copy(0, 4 * tileHeight, tileWidth, tileHeight));

    setPos(scene_width /2, scene_height /2);

    // Enable key events
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
}

const QPixmap &Mario::getSheet() const {
    return sheet;
}

void Mario::setSheet(const QPixmap &sheet) {
    Mario::sheet = sheet;
}

Direction Mario::getPrevDirection() const {
    return prevDirection;
}

void Mario::setPrevDirection(Direction prevDirection) {
    Mario::prevDirection = prevDirection;
}

int Mario::getTileWidth() const {
    return tileWidth;
}

void Mario::setTileWidth(int tileWidth, QPixmap sheet) {
    Mario::tileWidth = sheet.width() / tileWidth;
}

int Mario::getTileHeight() const {
    return tileHeight;
}

void Mario::setTileHeight(int tileHeight, QPixmap sheet) {
    Mario::tileHeight = sheet.height() / tileHeight;
}

void Mario::keyPressEvent(QKeyEvent *event)  {
    if (event->key() == Qt::Key_Left) {
        setPos(x()-10, y());
        if (this->prevDirection != LEFT) {
            this->setPrevDirection(LEFT);
            this->setPixmap(this->getSheet().copy(3 * tileWidth, 6 * tileHeight, tileWidth, tileHeight));
        }
    }
    else if (event->key() == Qt::Key_Right) {
        setPos(x()+10, y());
        if (this->prevDirection != RIGHT) {
            this->setPrevDirection(RIGHT);
            this->setPixmap(this->getSheet().copy(0 * tileWidth , 6 * tileHeight, tileWidth, tileHeight));
        }
    }
    else if (event->key() == Qt::Key_Up) {
        setPos(x(), y()-10);
        if (this->prevDirection != UP) {
            this->setPrevDirection(UP);
            this->setPixmap(this->getSheet().copy(3 * tileWidth, 4 * tileHeight, tileWidth, tileHeight));
        }
    }
    else if (event->key() == Qt::Key_Down) {
        setPos(x(), y()+10);
        if (this->prevDirection != DOWN) {
            this->setPrevDirection(DOWN);
            this->setPixmap(this->getSheet().copy(0 * tileWidth, 4 * tileHeight, tileWidth, tileHeight));
        }
    }
}
