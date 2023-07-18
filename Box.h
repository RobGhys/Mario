//
// Created by robin on 17/07/23.
//

#ifndef MARIO_BOX_H
#define MARIO_BOX_H


#include <QKeyEvent>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "GameObject.h"

class Box : public GameObject {
private:

public:
    Box(double scene_height, double scene_width);
};


#endif //MARIO_BOX_H
