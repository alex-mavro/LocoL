#pragma once
#include <fstream>
#include <vector>
#include <filesystem>

#include "LocalFile.h"

class FileHandler
{
private:
	static LocalFile* handle_file(const std::filesystem::directory_entry& directory_entry, std::string& keyword);
	//static LocalFile parse_html(std::string entry);
public:
	static LocalFile* handle_entry(const std::filesystem::directory_entry& unfiltred_directory_entry, std::string& keyword);
};

