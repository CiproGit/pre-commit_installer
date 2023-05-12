#ifndef FILE_SYSTEM_H
#define FILE_SYSTEM_H

#include <string>
#include <vector>

namespace file_system {
	void find(const std::string &directory, const std::string &file_name, std::vector<std::string> &file_list, const bool recursive = true); // It returns all the file paths with the given file name inside the given directory
} // namespace file_system

#endif // FILE_SYSTEM_H
