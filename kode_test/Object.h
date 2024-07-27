#pragma once
#include <iostream>

class string;

class Object
{
public:
	Object(std::string& line);

	std::string getName() const;
	std::string getType() const;
	std::string getGroup() const;
	double getTimeOfCreation() const;
	double getDistance() const;
	std::pair<double, double> getCoords() const; 

	void setGroup(const std::string& group); 

	void print() noexcept;

private:
	std::string name_, type_, group_;
	std::pair<double, double> coords_;
	double time_of_creation_;
	double distance_;
};

