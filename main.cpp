#include <iostream>
#include <vector>
#include "manageList.h"

// Prints out all tasks
void listAll(std::vector<Task> taskList)
{
	// Iterate through all tasks in the list
	for (auto task : taskList)
	{
		std::cout << "Description: " << task.getDescription() << std::endl;
		std::cout << "ID: " << task.getId() << std::endl;
		std::cout << "Name: " << task.getName() << std::endl;
	}
}

int main()
{
	std::vector<Task> taskList;
	int id{ 0 };
	for (;;)
	{
		std::cout << "Create a task by writing its name:\n";
		std::string input, description;
		std::getline(std::cin, input);
		std::string token = input.substr(0, input.find(" "));
		std::cout << "TOKEN: " << token << std::endl;
		//system("CLS");
		Task task(input, description, id);
		taskList.push_back(task);
		id++;
		listAll(taskList);
	}
	return 0;
}
