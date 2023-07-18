//
// Created by robin on 17/07/23.
//

#include <QGraphicsScene>
#include "Utils.h"
#include "Mario.h"
#include "Box.h"

bool Utils::isValidPath(std::string fileName) {
    std::filesystem::path path = std::filesystem::current_path();
    std::cout << "Current path is " << path << std::endl;

    std::filesystem::path imagePath = path / fileName;
    std::cout << "Image path is " << imagePath << std::endl;
    std::ifstream imageFile(imagePath);

    if (imageFile.is_open()) {
        std::cout << "Successfully opened " << imagePath << std::endl;
        imageFile.close();
        return true;
    } else {
        std::cout << "Failed to open " << imagePath << std::endl;
        return false;
    }
}

bool Utils::readMap(std::string fileName, QGraphicsScene *scene) {
    std::ifstream mapFile(fileName);

    if (mapFile.is_open()) {
        char tile;
        while (mapFile.get(tile)) {
            if (tile == '\n') {
                std::cout << std::endl;
            } else {
                if (tile == 'P') {
                    // Add Mario
                    Mario *mario = new Mario(scene->width() /2, scene->height() /2);
                    scene->addItem(mario);
                } else if (tile == '#') {
                    Box * box = new Box(scene->width() /2, scene->height() /2);
                    scene->addItem(box);

                    scene->addItem(box);
                } else {
                    std::cout << tile;
                }
            }
        }
        mapFile.close();
        return true;
    } else {
        std::cout << "Unable to open map file";
        return false;
    }
}