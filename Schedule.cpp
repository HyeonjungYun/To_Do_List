#include "Schedule.h"

Schedule::Schedule() {
	this->_name = "";
	this->_done = false;
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
	this->_name = str;
}

Schedule::~Schedule() {

}

string Schedule::getName() {
	return _name;
}

bool Schedule::is_done() {
	return _done;
}

void Schedule::done() {
	this->_done = 1;
}

string Schedule::getSchedule() {
	return _name + (_done ? " done" : " notDone");
}