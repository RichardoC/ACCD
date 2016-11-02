//
// Created by Richard Finlay Tweed on 30/10/2016.
//

#include <string>
#include <vector>
#include <fstream>
#include <dirent.h>
#include "Analysis.h"
#include "CellUser.h"

std::vector<CellUser> importFromFile (std::string fileLoc,int samplingRate = -1){
    std::ifstream input(fileLoc.c_str());
    std::vector<CellUser> output;
    std::string line;

    long loops = 0;
    //looping over all the lines ie users in the file

    //skipping the header
    getline(input, line);
    while(!input.eof()) {
        if (samplingRate >0 && loops%samplingRate == 0){
            loops ++;
            continue;
        }
        loops ++;
        getline(input, line);
        if(line.size()==0){
            continue;
        }
        try {
            CellUser temp(line);
            output.push_back(temp);
        }
        catch (...){

        }

    }
    return output;
}


/*function... might want it in some class?*/
int getdir (std::string dir, std::vector<std::string> &files)
{
    DIR *dp;
    struct dirent *dirp;
    if((dp  = opendir(dir.c_str())) == NULL) {
        printf("Error(,%i) opening %s\n",errno,dir.c_str());
        return errno;
    }

    while ((dirp = readdir(dp)) != NULL) {
        files.push_back(std::string(dirp->d_name));
    }
    closedir(dp);
    return 0;
}

std::vector<CellUser> importFromDirectory(std::string directory,int samplingRate = -1){
    std::vector<std::string> files;

    getdir(directory,files);

    std::vector<CellUser> importedUsers;

    for(int i=0; i< files.size(); i++){
        std::string file = files.at(i);
        if(file[0]=='.'){
            continue;
        }
        std::string fileString = directory+file;
        std::vector<CellUser> fromFile = importFromFile(fileString,samplingRate);
        printf("\n%s\n",file.c_str());
        printf("Imported %lu Users\n", fromFile.size());
//        allUsers.assign(old_vector.begin(),old_vector.end());
//        std::copy(fromFile.begin(),fromFile.end(),importedUsers.end()) ;
        importedUsers.insert(importedUsers.end(), fromFile.begin(), fromFile.end());
    }
    return importedUsers;

}



int main() {
//    std::string file1 = "/Users/richardf/GitHub/ACCD/data_export_cobercat/data_export_1-2015.csv";

//    std::vector<CellUser> first = importFromFile(file1);

    std::vector<CellUser> allUsers = importFromDirectory("/Users/richardf/GitHub/ACCD/data_export_cobercat/");

    printf("\n Imported %lu cell users", allUsers.size());
    printf("\nFinished\n");


    return 0;
}