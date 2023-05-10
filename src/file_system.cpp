#include "file_system.h"
#include <windows.h>
#include <filesystem>

using namespace std;

namespace file_system {
	void find(const std::string directory, const std::string file_name, std::vector<std::string> &file_list, const bool recursive) {
		string file_to_find = directory + "/*.*";

		WIN32_FIND_DATA find_data;
		HANDLE handle_file_find = FindFirstFile(file_to_find.c_str(), &find_data);
		if (handle_file_find) {
			do {
				string found_file_name = find_data.cFileName;
				if ((found_file_name == ".") || (found_file_name == "..")) continue;

				string found_file_path = directory + "/" + found_file_name;
				if (recursive && (filesystem::is_directory(found_file_path))) find(found_file_path, file_name, file_list);
				else {
					string found_file_name = filesystem::path(found_file_path).filename().string();
					if (found_file_name == file_name) file_list.push_back(filesystem::path(found_file_path).string());
				}
			} while (FindNextFile(handle_file_find, &find_data));

			FindClose(handle_file_find);
		}
	}
} // namespace file_system
