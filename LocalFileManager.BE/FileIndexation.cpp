#include "FileIndexation.h"

#include "FileHandler.h"
#include "filesystem"
namespace fs = std::filesystem;


std::vector<LocalFile> FileIndexation::getAllMatchingFiles(const std::filesystem::path& sub_directory_path, std::string& keyword)
{
	std::vector<LocalFile> files;

	const bool is_directory = fs::is_directory(sub_directory_path);

	if(is_directory)
	{
		for (const auto& entry : fs::directory_iterator(sub_directory_path))
		{
			if (entry.is_directory())
			{

				for (const auto& entry : fs::directory_iterator(entry.path()))
				{
					const std::vector<LocalFile> filtred_subdirectory_files = getAllMatchingFiles(entry.path(), keyword);
					for (const LocalFile& filtred_subdirectory_file : filtred_subdirectory_files)
					{
						files.push_back(filtred_subdirectory_file);
					}
				}
			}
			else
			{
				LocalFile* suitable_entry = FileHandler::handle_entry(entry, keyword);
				if (suitable_entry != nullptr)
				{
					files.push_back(*suitable_entry);
				}
			}
		}
	}
	else
	{
		LocalFile* suitable_entry = FileHandler::handle_entry(*new std::filesystem::directory_entry(sub_directory_path), keyword);
		if (suitable_entry != nullptr)
		{
			files.push_back(*suitable_entry);
		}
	}
	
	return files;
}
