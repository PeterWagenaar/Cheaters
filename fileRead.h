#include <string>
#include <vector>

#ifndef CHEATERS_FILEREAD_H
#define CHEATERS_FILEREAD_H


class fileRead {
private:
    std::string text;
    int words;

public:
    fileRead();

    void read(std::string fileName, std::string dirName);

    int getMaxWords();

    std::string getText();

};

#endif //CHEATERS_FILEREAD_H
