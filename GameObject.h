//
// Created by robin on 18/07/23.
//

#ifndef MARIO_GAMEOBJECT_H
#define MARIO_GAMEOBJECT_H


#include <QPixmap>
#include <QGraphicsPixmapItem>
#include <QDebug>

class GameObject : public QGraphicsPixmapItem {
private:
    QPixmap sheet;
    int tileWidth{};
    int tileHeight{};

    void setTileWidth(int tileWidth, QPixmap sheet);
    void setTileHeight(int tileHeight, QPixmap sheet);

public:
    GameObject(double scene_height, double scene_width);
    const QPixmap &getSheet() const;
    void setSheet(const QPixmap &sheet);
    int getTileWidth() const;
    int getTileHeight() const;
};



#endif //MARIO_GAMEOBJECT_H
