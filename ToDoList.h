#ifndef _TO_DO_LIST_
#define _TO_DO_LIST_
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Schedule.h"
using namespace std;

class ToDoList {
private:
	const char* fileName;
	vector<Schedule> scheduleList;
public:
	ToDoList();
	ToDoList(const char* fileName);
	~ToDoList();
	void view();
	void create();
	void addSchedule();
	void doneSchedule();
	void removeSchedule();
	void setPriority();
	void selectUpAndDown(int index);
	void upPriority(int index);
	void downPriority(int index);
	void read();
	void save();
};

#endif _TO_DO_LIST_