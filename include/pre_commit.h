#ifndef PRE_COMMIT_H
#define PRE_COMMIT_H

#include <vector>
#include <string>

const std::string GIT_BASH = "\"C:/Program Files/Git/git-bash.exe\" -c";
const std::string PRE_COMMIT_INSTALL = "pre-commit install";
const std::string PRE_COMMIT_CONFIG = ".pre-commit-config.yaml";

class Pre_commit {
private:
	std::vector<std::string> pre_commit_config_list;

public:
	Pre_commit(const std::string &project_directory);
	virtual ~Pre_commit();
	std::vector<std::string> get_config_list() const;
	bool install() const;
};

#endif // PRE_COMMIT_H
