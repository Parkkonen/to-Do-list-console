#include <iostream>
#include <vector>
#include <sstream>
#include <map>

#include "manageList.h"

enum class Commands
{
	ShowAll,
	Create,
	Delete,
	DeleteAll,
	Help,
	Unknown
};

struct CommandInfo {
	std::string name;
	std::string description;
};

std::vector<CommandInfo> commandInfoList = {
	{"ShowAll", "Show all tasks"},
	{"Create", "Create a new task"},
	{"Delete", "Delete a task by ID"},
	{"DeleteAll", "Delete all tasks"},
	{"Help", "Show available commands"}
};
void help()
{
	for (auto command : commandInfoList)
	{
		std::cout << command.name << " " << command.description << std::endl;
	}
}

std::vector<Task> taskList;
// Prints out all tasks
void listAll()
{
	// Iterate through all tasks in the list
	for (auto task : taskList)
	{
		std::cout << "ID: " << task.getId() << std::endl;
		std::cout << "Name: " << task.getName() << std::endl;
		std::cout << "Description: " << task.getDescription() << std::endl;
	}
}

Commands figureOutWhichCommand(const std::string& command) {
	std::map<std::string, Commands> stringToEnumMap = {
		{"ShowAll", Commands::ShowAll},
		{"Create", Commands::Create},
		{"Delete", Commands::Delete},
		{"DeleteAll", Commands::DeleteAll},
		{"Help", Commands::Help},
		{"Unknown", Commands::Unknown}
	};

	auto it = stringToEnumMap.find(command);
	if (it != stringToEnumMap.end())
	{
		return it->second;
	}
	else
	{
		return Commands::Unknown;
	}
}

int main()
{
	int id{ 0 };
	for (;;)
	{
		std::cout << "Create a task by writing its name:\n";
		std::string command, input, description;
		int num;
		std::vector<Task>::iterator iterator;
		std::getline(std::cin, input);
		std::istringstream iss(input);

		iss >> command;
		iss >> description;

		Task task(input, description, id);
		switch (figureOutWhichCommand(command))
		{
		case Commands::ShowAll:
			system("CLS");
			listAll();
			break;
		case Commands::Create:
			taskList.push_back(task);
			id++;
			break;
		case Commands::Delete:
			try {
				num = std::stoi(description);
				if (num >= 0 && num < taskList.size()) {
					iterator = taskList.begin() + num;
					taskList.erase(iterator);
					std::cout << "Task with ID " << num << " deleted" << std::endl;
				}
				else {
					std::cout << "Invalid ID: " << num << std::endl;
				}
			}
			catch (const std::invalid_argument& e) {
				std::cout << "Invalid input. Please enter a valid number." << std::endl;
			}
			catch (const std::out_of_range& e) {
				std::cout << "Input out of range. Please enter a valid number." << std::endl;
			}
			break;
		case Commands::DeleteAll:
			id = 0;
			taskList.clear();
			break;
		case Commands::Help:
			help();
			break;
		case Commands::Unknown:
			std::cout << "Command not found" << std::endl;
			break;
		}
	}
	return 0;
}
