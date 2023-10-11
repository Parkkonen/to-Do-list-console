#pragma once
#include <string>
#include <vector>

class Task {
public:
	Task(const std::string& name, const std::string& description, const int& id)
		: name(name), description(description), id(id) {
	}
	std::string getName() const {
		return name;
	}

	std::string getDescription() const {
		return description;
	}
	int getId() const {
		return id;
	}
private:
	std::string name;
	std::string description;
	int id;
};
