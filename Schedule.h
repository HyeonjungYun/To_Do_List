#ifndef _SCHEDULE_
#define _SCHEDULE_

#include <iostream>
using namespace std;

class Schedule {
private:
	string _name;
	bool _done;
public:
	Schedule();
	Schedule(string name);
	~Schedule();

	string getName();
	string getSchedule();
	bool is_done();
	void done();
};

#endif _SCHEDULE_