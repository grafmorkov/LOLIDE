#include <iostream>
#include "filemanager.h"

namespace lolide::fm{
    void FileManager::read() {
        if (!file.is_open()) return;

        file.seekg(0);
        std::string lineStr;
        while (std::getline(file, lineStr)) {
            std::cout << lineStr << std::endl;
            line++;
        }
        file.clear();
    }

    void FileManager::write(const std::string& txt) {
        if (!file.is_open()) return;

        file << txt;
        file.flush();
    }
    
}