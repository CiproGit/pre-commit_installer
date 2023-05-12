#ifndef EXECUTION_H
#define EXECUTION_H

#include <string>

namespace execution {
	void execute(const std::string &executable, const std::string &parameter); // It runs the given executable in a new asynchronous process
	void execute_and_wait(const std::string &executable, const std::string &parameter); // It runs the given executable in a new synchronous process
	void cmd_execute(const std::string &command); // It executes the given command in a new cmd.exe shell; cmd.exe is started in a new asynchronous process
} // namespace execution

#endif // EXECUTION_H
