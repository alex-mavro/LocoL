#include "FileIndexation.h"

#include <iostream>

#include "FileHandler.h"

int main()
{
    

    while (true) {

        std::string keyword;

        std::cin >> keyword;

        std::vector<LocalFile> allIndexedFiles = FileIndexation::getAllMatchingFiles("C:/Users/alexa/Desktop/teamstep", keyword);
        std::cout << std::endl << std::endl << std::endl << std::endl;
        for (const LocalFile& indexed_file : allIndexedFiles)
        {
            std::cout << "[x]" << indexed_file.fileName << std::endl;
        }
        std::cout << "------------------------" << std::endl;
    }
}
