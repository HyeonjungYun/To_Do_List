#include "ToDoList.h"

ToDoList::ToDoList() {
	fileName = nullptr;
}

ToDoList::ToDoList(const char* fileName) {
	this->fileName = fileName;
}

ToDoList::~ToDoList() {
	
}

void ToDoList::create() {
	bool is_finished = 0;
	int count = 1;
	string task;

	while (!is_finished) {
		cout << count << ": ";

		getline(cin, task);

		if (task == "") {
			is_finished = 1;
			continue;
		}
		scheduleList.push_back(task);
		count++;
	}
}

void ToDoList::read() {
	fstream fs(fileName, fstream::in);
	scheduleList.clear();

	string line;

	while (getline(fs, line)) {
		Schedule schedule(line);
		scheduleList.push_back(schedule);
	}

	fs.close();
}

void ToDoList::save() {
	fstream fs(fileName, fstream::out);

	for (Schedule schedule : scheduleList) {
		fs << schedule.getName() << " " << (schedule.is_done() ? "done" : "notDone") << endl;
	}

	fs.close();
}

void ToDoList::view() {
	fstream fs(fileName, fstream::in);
	
	string line;

	while (getline(fs, line)) {
		cout << line << endl;
	}

	fs.close();
}

void ToDoList::addSchedule() {
	int index = scheduleList.size();

	string schedule;

	while (1) {
		cout << ++index << ": ";

		getline(cin, schedule);
		if (schedule == "") break;
	}

	save();
}