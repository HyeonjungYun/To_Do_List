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
	bool is_done();
};

#endif _SCHEDULE_