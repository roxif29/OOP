#pragma once
#include <algorithm>
#include <vector>
using std::vector;

class Observer
{

public:
	virtual void update() = 0;
};


class Observable {
	vector<Observer*> observers;
protected:
	void notify() {
		for (auto o : observers) {
			o->update();
		}
	}
public:
	void addObserver(Observer* obs) {
		observers.push_back(obs);
	}
	void removeObserver(Observer* obs) {
		observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
	}
	
};
