#include <iostream>
#include <fstream>
#include <string>

namespace lolide::fm {

class FileManager {
private:
    std::fstream file;
    int line;
    int column;

public:
    FileManager(const std::string& filename)
        : line(1), column(1)
    {
        file.open(filename, std::ios::in | std::ios::out | std::ios::app); 
        if (!file.is_open()) {
            std::cerr << "Error: Failed to open the file " << filename << std::endl;
        }
    }
    ~FileManager() {
        if (file.is_open()) {
            file.close();
        }
    }

    void read();
    void write(const std::string& txt);
};

}