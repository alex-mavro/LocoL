#include "FileHandler.h"

#include <string>


LocalFile* FileHandler::handle_file(const std::filesystem::directory_entry& directory_entry, std::string& keyword)
{
	std::ifstream file(directory_entry.path());
	std::string html_content;
	if (file.is_open()) {

		std::string line;
		while (std::getline(file, line)) {
			html_content += line + '\n';
		}
		file.close();

		std::transform(html_content.begin(), html_content.end(), html_content.begin(),
			[](unsigned char c) { return std::tolower(c); } // correct
		);
		std::transform(keyword.begin(), keyword.end(), keyword.begin(),
			[](unsigned char c) { return std::tolower(c); } // correct
		);

		const bool contains_keyword = html_content.find(keyword) != std::string::npos;

		if(contains_keyword)
		{
			LocalFile* suiting_file = new LocalFile(directory_entry.path().extension().string(), directory_entry.path().filename().string(), directory_entry.path().string());
			std::cout << "File that includes '" << keyword << "': " << suiting_file->fileName << std::endl;
			return suiting_file;
	
		}
		/*else
		{
			std::cout << "File that DOESN'T includes '" << keyword << "': " << suiting_file->fileName << std::endl;
		}*/
		
	}
	return nullptr;
}

LocalFile* FileHandler::handle_entry(const std::filesystem::directory_entry& unfiltred_directory_entry, std::string& keyword)
{
	//std::vector<LocalFile> filtred_entries;

	//std::string fileExtension = unfiltred_directory_entry.path().extension().string();
	//std::string fileName = unfiltred_directory_entry.path().filename().string();
	//if (fileExtension == ".xlsx")
	//{
	//	std::cout << unfiltred_directory_entry.path().filename() << ": Excel" << std::endl;

	//}
	//else if (fileExtension == ".pdf")
	//{
	//	std::cout << fileName << ": pdf" << std::endl;
	//}
	//else if (fileExtension == ".html" || fileExtension == ".htm")
	//{

	//	//handle_file(unfiltred_directory_entry);

	//}
	//else if (fileExtension == ".json")
	//{
	//	std::cout << fileName << ": data/json" << std::endl;
	//}
	//else if (fileExtension == ".xml")
	//{
	//	std::cout << fileName << ": data/xml" << std::endl;
	//}
	//else
	//{
	//	std::cout << fileName << ": unknown" << std::endl;
	//}


	//std::cout << "---------------" << std::endl;
	return handle_file(unfiltred_directory_entry, keyword);
}
