//
// Created by peter on 5/2/2019.
//

#include "fileRead.h"
#include <string>
#include <fstream>
#include <iostream>


fileRead::fileRead(){
    this->words = 0;
}

void fileRead::read(std::string fileName, std::string dirName){
    std::ifstream inFile (dirName + "\\" + fileName);
    std::string s;
    text = "";

    if(!inFile){
        std::cerr << "Unable to open file " << fileName << std::endl;
    }
    else {
        while (inFile >> s) {
            for (unsigned int i = 0; i < s.length(); i++) {
                if (!isalnum(s[i])) {
                    s.erase(i);
                } else {
                    s[i] = (char) tolower(s[i]);
                }
            }
            text += s + " ";
        }
        try {
            throw std::stoi(s);
        }
        catch (int x){
            if (this->words < std::stoi(s)) {
                this->words = std::stoi(s);
            }
        }
        catch (...) {}
    }
}

int fileRead::getMaxWords() {
    return this->words;
}

std::string fileRead::getText() {
    return this->text;
}
