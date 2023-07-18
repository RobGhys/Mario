//
// Created by robin on 17/07/23.
//

#include "Box.h"

Box::Box(double scene_height, double scene_width) : GameObject(scene_height, scene_width) {
    // Assign sprite
    this->setPixmap(this->getSheet().copy(9 * this->getTileWidth(), 6 * this->getTileHeight(),
                                          this->getTileWidth(), this->getTileHeight()));

    setPos(5, 10);
}
