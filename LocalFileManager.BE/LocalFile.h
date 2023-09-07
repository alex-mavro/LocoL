#pragma once
#include <iostream>

class LocalFile
{
public:
	std::string fileType;
	std::string fileName;
	std::string filePath;
	std::string fileHighlight;

	LocalFile(std::string fileType, std::string fileName, std::string filePath, std::string fileHighlight);
	LocalFile(std::string fileType, std::string fileName, std::string filePath);

};
