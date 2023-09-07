#pragma once
#include <vector>
#include <filesystem>
namespace fs = std::filesystem;

#include "LocalFile.h"

class FileIndexation
{
public:
	static std::vector<LocalFile> getAllMatchingFiles(const std::filesystem::path& sub_directory_path, std::string& keyword);
	static std::vector<fs::directory_entry> localFiles;
};

