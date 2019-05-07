#include <string>

#ifndef CHEATERS_PLAGIARISMCATCHER_H
#define CHEATERS_PLAGIARISMCATCHER_H

class plagiarismCatcher{
private:
        int chunkSize;
        std::string file;

    public:
        struct hashNode{

            int fileNum = 0;
            hashNode* next = nullptr;

        };

        plagiarismCatcher();

        explicit plagiarismCatcher(int size);

        int getChunkSize();

        void setChunkSize(int size);

        std::string makeChunks(std::string file);

        void hashFile(std::string const &file1, hashNode* hash[], int size, int filenum);

};

#endif //CHEATERS_PLAGIARISMCATCHER_H
