#include "plagiarismCatcher.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>

plagiarismCatcher::plagiarismCatcher(){
    this->chunkSize = 5;
}

plagiarismCatcher::plagiarismCatcher(int size){
    this->chunkSize = size;
}


int plagiarismCatcher::getChunkSize(){
    return chunkSize;
}

void plagiarismCatcher::setChunkSize(int size){
    this->chunkSize = size;
}

std::string plagiarismCatcher::makeChunks(std::string file){
    std::vector<std::string> words;
    std::istringstream iss(file);
    std::string word;

    file = "";

    while(iss >> word){
        words.push_back(word);
    }
    int count = 1;

    if(words.size()<=chunkSize){
        for(auto it = words.begin(); it != words.end(); ++it){
            auto tempit = it;
            file += *tempit;
            count++;
            tempit++;
        }
    }
    else {
        for (auto it = words.begin(); it != words.end() - chunkSize; ++it) {
            auto tempit = it;
            while ((count % (chunkSize + 1)) != 0) {
                file += *tempit;
                count++;
                tempit++;
            }
            file += " ";
            count = 1;
        }
    }

    return file;
}

void plagiarismCatcher::hashFile(std::string const &file, hashNode* hash[], int size, int filenum){
    std::vector<std::string> words;
    std::istringstream iss(file);
    std::string word;
    plagiarismCatcher::hashNode* temp;
    int sum;


    while(iss >> word){
        sum = 0;

        for(int i =0; i<word.length(); i++){
            sum += (word[word.length()-i-1])*(int)(std::pow(13.0, i%chunkSize));
            sum=sum%size;
        }

        if(hash[sum]== nullptr){
            temp = new plagiarismCatcher::hashNode;
            temp->fileNum = filenum;
            temp->next = hash[sum];

            hash[sum] = temp;
        }

        else if(hash[sum]->fileNum!=filenum) {
            temp = new plagiarismCatcher::hashNode;
            temp->fileNum = filenum;
            temp->next = hash[sum];

            hash[sum] = temp;
        }

    }
}