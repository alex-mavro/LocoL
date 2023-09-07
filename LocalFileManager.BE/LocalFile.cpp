#include "LocalFile.h"

LocalFile::LocalFile(std::string fileType, std::string fileName, std::string filePath)
{
	this->fileType = fileType;
	this->fileName = fileName;
	this->filePath = filePath;
}

LocalFile::LocalFile(std::string fileType, std::string fileName, std::string filePath, std::string fileHighlight)
{
	this->fileType = fileType;
	this->fileName = fileName;
	this->filePath= filePath;
	this->fileHighlight= fileHighlight;
}

