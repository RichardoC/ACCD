//
// Created by Richard Finlay Tweed on 30/10/2016.
//

#include <string>
#include <vector>
#include <fstream>
#include "Analysis.h"
#include "CellUser.h"

std::vector<CellUser> importFromFile (std::string fileLoc){
    std::ifstream input(fileLoc.c_str());
    std::vector<CellUser> output;
    std::string line;

    long loops = 0;
    //looping over all the lines ie users in the file

    //skipping the header
    getline(input, line);
    while(!input.eof()) {
        if (loops%1000000 ==0){
            printf("imported %lu\n", loops);
        }
        loops ++;
        getline(input, line);
        CellUser temp(line);
        output.push_back(temp);

    }
    return output;
}

int main() {
    std::string file1 = "/Users/richardf/GitHub/ACCD/data_export_cobercat/data_export_01-2016.csv";

    std::vector<CellUser> first = importFromFile(file1);

}