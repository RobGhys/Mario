//
// Created by robin on 17/07/23.
//

#ifndef MARIO_MARIO_H
#define MARIO_MARIO_H


#include <QPixmap>
#include <QDebug>
#include <QGraphicsPixmapItem>
#include "Direction.h"

class Mario : public QGraphicsPixmapItem {
public:
    Mario(double scene_height, double scene_width);

    int getTileWidth() const;
    int getTileHeight() const;
    void keyPressEvent(QKeyEvent *event) override;

    const QPixmap &getSheet() const;

    void setSheet(const QPixmap &sheet);

    Direction getPrevDirection() const;

    void setPrevDirection(Direction prevDirection);

private:
    QPixmap sheet;
    int tileWidth{};
    int tileHeight{};
    Direction prevDirection;

    void setTileWidth(int tileWidth, QPixmap sheet);

    void setTileHeight(int tileHeight, QPixmap sheet);
};



#endif //MARIO_MARIO_H
