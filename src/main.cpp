#include "pre_commit.h"
#include "config.h"
#include <iostream>
#include <algorithm>

using namespace std;

void print_about() {
	string version_string = to_string(VERSION_MAJOR) + "." + to_string(VERSION_MINOR) + "." + to_string(VERSION_PATCH);

	cout << "******************************\n";
	cout << "    PRE-COMMIT INSTALLER\n";
	cout << "    Version " + version_string + "\n";
	cout << "    Developed by\n";
	cout << "    Federico Cipressi\n";
	cout << "******************************\n" << endl;
}

string sanitize(string input) {
	replace(input.begin(), input.end(), '\\', '/');
	return input;
}

int main(int argc, char *argv[]) {
	print_about();

	if (argc == 2) { // 1 argument
		cout << "Searching for pre-commit-config.yaml..." << endl;

		Pre_commit pre_commit(sanitize(argv[1]));
		cout << "I found the following pre-commit-config.yaml:\n";
		for (const auto &pre_commit_config : pre_commit.get_config_list()) {
			cout << pre_commit_config << "\n";
		}
		cout << endl;

		cout << "Executing pre-commit install...\n";
		if (pre_commit.install()) cout << "Done!" << endl;
		else cout << "Nothing to do" << endl;
	}
	else {
		cerr << "Error: I need 1 argument\n";
		cerr << "Usage: pre-commit_installer.exe [project directory]" << endl;
		return EXIT_FAILURE;
	}

	cout << "\nEnd" << endl;
	return EXIT_SUCCESS;
}
