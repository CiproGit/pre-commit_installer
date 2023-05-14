#include "pre_commit.h"
#include <iostream>
#include <algorithm>

using namespace std;

string sanitize(string input) {
	replace(input.begin(), input.end(), '\\', '/');
	return input;
}

int main(int argc, char *argv[]) {
	cout << "******************************\n";
	cout << "*    PRE-COMMIT INSTALLER    *\n";
	cout << "*    Version 1.0.0           *\n";
	cout << "*    Developed by            *\n";
	cout << "*    Federico Cipressi       *\n";
	cout << "******************************\n" << endl;

	if (argc == 2) { // 1 argument
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
