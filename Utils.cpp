//
// Created by robin on 17/07/23.
//

#include "Utils.h"

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