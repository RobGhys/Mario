//
// Created by robin on 17/07/23.
//

#ifndef MARIO_UTILS_H
#define MARIO_UTILS_H

#include <filesystem>
#include <fstream>
#include <iostream>

class Utils {
private:

public:
    bool isValidPath(std::string fileName);

    static bool readMap(std::string fileName, QGraphicsScene *scene);
};


#endif //MARIO_UTILS_H
