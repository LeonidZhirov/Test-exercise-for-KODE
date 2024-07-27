#include "Object.h"
#include <string>
#include <sstream>
#include <iomanip>
#include <windows.h>
#include <math.h>

Object::Object(std::string& line)
{
	std::istringstream iss(line);
	std::string word;
	unsigned number_of_words = 0;

	while (iss >> word) {
		switch (number_of_words) {
		case 0:
			name_ = word;
			break;
		case 1:
			coords_.first = std::atof(word.c_str());
			break;
		case 2:
			coords_.second = std::atof(word.c_str());
			break;
		case 3:
			type_ = word;
			break;
		case 4: 
			time_of_creation_ = std::atof(word.c_str());
			break;
		}

		number_of_words++;
	}

	iss.clear();

	distance_ = std::hypot(coords_.first, coords_.second);
}

std::string Object::getName() const
{
	return name_;
}

std::string Object::getType() const
{
	return type_;
}

std::string Object::getGroup() const
{
	return group_;
}

double Object::getTimeOfCreation() const
{
	return time_of_creation_;
}

double Object::getDistance() const
{
	return distance_;
}

std::pair<double, double> Object::getCoords() const
{
	return coords_;
}

void Object::setGroup(const std::string& group)
{
	group_ = group;
}

void Object::print() noexcept
{
	std::cout << name_ << ' ' << std::setprecision(7) << coords_.first << ' ' << coords_.second << ' ' 
		<< type_ << ' ' << std::setprecision(15) << time_of_creation_ << std::endl;
}
