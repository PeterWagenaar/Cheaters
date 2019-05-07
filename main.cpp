#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "plagiarismCatcher.h"
#include "getDirectory.h"
#include "fileRead.h"

using namespace std;

const static int HASH_SIZE = 105229;

/*function... might want it in some class?*/
struct plagiarism{
    int numCopies = 0;
    string file = "";
    string file2 = "";

};

bool compareByLength(const plagiarism &a, const plagiarism &b)
{
    return a.numCopies > b.numCopies;
}

int main(int argc, char *argv[]){
    string direc = argv[1];
    int CHUNK_SIZE = atoi(argv[2]);
    int MAX_HITS = atoi(argv[3]);

    getDirectory directory;
    fileRead f;
    plagiarismCatcher p(CHUNK_SIZE);

    plagiarismCatcher::hashNode *temp;
    plagiarismCatcher::hashNode *temp2;

    string dir = string(direc);
    vector<string> files = vector<string>();

    directory.getdir(dir,files);

    int** copies;

    copies = (int**)malloc(sizeof(int*)*files.size());
    for(int i  = 0; i<files.size();i++){
        copies[i] = (int*)malloc(sizeof(int)*files.size());
    }

    for(int i = 0; i<files.size(); i++){
        for(int j = 0; j<files.size(); j++){
            copies[i][j] = 0;
        }
    }

    plagiarismCatcher::hashNode* hashTable[HASH_SIZE];

    for(int i = 0; i< HASH_SIZE; i++){
        hashTable[i] = nullptr;
    }

    string s;
    for (unsigned int i = 0;i < files.size();i++) {
        cout << i << ": " + files[i]<< endl;
        f.read(files[i],dir);
        s = f.getText();
        p.hashFile(p.makeChunks(s), hashTable, HASH_SIZE, i);
    }

    for(int i = 0; i < HASH_SIZE; i++) {
        temp = hashTable[i];
        temp2 = hashTable[i];
        while (temp != nullptr) {
            while (temp2 != nullptr) {
                if((temp->fileNum)!=(temp2->fileNum)){
                    copies[temp->fileNum][temp2->fileNum]++;
                }
                temp2 = temp2->next;
            }
            temp = temp->next;
            temp2 = temp;
        }
    }

    vector<plagiarism> c;
    plagiarism plag;
    for(int i = 0; i<files.size(); i++){
        for(int j = 0; j<files.size(); j++) {
            if(copies[i][j]>MAX_HITS){
                plag.file = files[i];
                plag.file2 = files[j];
                plag.numCopies = copies[i][j];
                c.push_back(plag);
            }
        }
    }

    std::sort(c.begin(), c.end(), compareByLength);

    for(auto &i: c){
        cout << i.numCopies << ": " << i.file + " and " + i.file2 << endl;
    }

    for(int i = 0; i<files.size() ; i++){
        free(copies[i]);
    }
    free(copies);

    return 0;
}
