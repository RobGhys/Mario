//
// Created by robin on 18/07/23.
//

#include "GameObject.h"

GameObject::GameObject(double scene_height, double scene_width) : QGraphicsPixmapItem() {

    // Link sprites
    this->setSheet(QPixmap("../resources/Tilesheet/sokoban_tilesheet.png"));
    if (this->sheet.isNull()) {
        qDebug() << "Did not find image";
    } else {
        qDebug() << "Loading Mario image";
    }

    this->setTileHeight(8, sheet);
    this->setTileWidth(13, sheet);
}


const QPixmap &GameObject::getSheet() const {
    return sheet;
}

void GameObject::setSheet(const QPixmap &sheet) {
    GameObject::sheet = sheet;
}

int GameObject::getTileWidth() const {
    return tileWidth;
}

void GameObject::setTileWidth(int tileWidth, QPixmap sheet) {
    GameObject::tileWidth = sheet.width() / tileWidth;
}

int GameObject::getTileHeight() const {
    return tileHeight;
}

void GameObject::setTileHeight(int tileHeight, QPixmap sheet) {
    GameObject::tileHeight = sheet.height() / tileHeight;
}