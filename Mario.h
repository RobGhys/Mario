//
// Created by robin on 17/07/23.
//

#ifndef MARIO_MARIO_H
#define MARIO_MARIO_H


#include <QPixmap>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include "Direction.h"
#include "GameObject.h"

class Mario : public GameObject {
private:
    Direction prevDirection;

public:
    Mario(double scene_height, double scene_width);

    void keyPressEvent(QKeyEvent *event) override;
    Direction getPrevDirection() const;
    void setPrevDirection(Direction prevDirection);
};



#endif //MARIO_MARIO_H
