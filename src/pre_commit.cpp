#include "pre_commit.h"
#include "execution.h"
#include "file_system.h"
#include <filesystem>

using namespace std;

Pre_commit::Pre_commit(const string project_directory) {
	file_system::find(project_directory, PRE_COMMIT_CONFIG, this->pre_commit_config_list);
}

Pre_commit::~Pre_commit() {}

vector<string> Pre_commit::get_config_list() const {
	return this->pre_commit_config_list;
}

bool Pre_commit::install() const {
	if (this->pre_commit_config_list.empty()) return false;
	
	// Execute for every directory containing pre-commit-config.yaml file
	for (const auto& pre_commit_config : this->pre_commit_config_list) {
		string directory = filesystem::path(pre_commit_config).parent_path().string();
		string command = "\"cd " + directory + " && " + PRE_COMMIT_INSTALL + "\"";

		execution::execute(GIT_BASH, command);
	}
	return true;
}
