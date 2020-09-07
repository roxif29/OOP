#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Car.h"
class Export
{
	void exportToCVS(const std::string& fName, const std::vector<Car>& cars);
	void exportToHTML(const std::string& fName, const std::vector<Car>& cars);
};

