//
// Created by peter on 5/2/2019.
//

#include "getDirectory.h"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <iostream>


int getDirectory::getdir (std::string& dir, std::vector<std::string> &files){
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == nullptr) {
        std::cout << "Error(" << errno << ") opening " << dir << std::endl;
        return errno;
    }

    while ((dirp = readdir(dp)) != nullptr) {
        if(dirp->d_name[dirp->strlen()-1]=='t'&&dirp->d_name[dirp->d_namlen-2]=='x'&&dirp->d_name[dirp->d_namlen-3]=='t'&&dirp->d_name[dirp->d_namlen-4]=='.'){
            files.emplace_back(std::string(dirp->d_name));
        }
    }

    closedir(dp);
    return 0;
}