#pragma once

#include <string>
#include <vector>
#include "Car.h"

	void exportToCVS(const std::string& fName, const std::vector<Car>& cars);
	void exportToHTML(const std::string& fName, const std::vector<Car>& cars);


