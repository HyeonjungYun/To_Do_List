#include "Schedule.h"

Schedule::Schedule() {
	this->_name = "";
}

Schedule::Schedule(string schedule) {
	int startD = schedule.find("done");
	int startND = schedule.find("notDone");

	string str;

	if (startD == -1 && startND == -1) {
		str = schedule;
		this->_done = 0;
	}
	else if (startD > -1 && startND == -1) {
		str = schedule.substr(0, startD - 1);
		this->_done = 1;
	}
	else if (startD == -1 && startND > -1) {
		str = schedule.substr(0, startND - 1);
		this->_done = 0;
	}
	this->_name = schedule;
}

Schedule::~Schedule() {

}

string Schedule::getName() {
	return _name;
}

bool Schedule::is_done() {
	return _done;
}