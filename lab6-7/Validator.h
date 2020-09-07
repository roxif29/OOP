#pragma once
#include <string>
#include"Car.h"
#include <vector>
using std::string;
using std::vector;
using std::ostream;

class ValidateException {
	string msg;
public:
	ValidateException(const string& msg):msg{msg}{}
	string getMsg() { return msg; }

};
class Validator{
public:
	void validate(const Car& c);
};

