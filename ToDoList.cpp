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
	scheduleList.clear();
	int index = scheduleList.size();

	string task;

	while (1) {
		cout << ++index << ": ";

		getline(cin, task);
		if (task == "") break;
		Schedule schedule(task);
		scheduleList.push_back(task);
	}

	save();
}

void ToDoList::doneSchedule() {
	read();

	int order = 1;

	for (Schedule schedule : scheduleList) {
		cout << order << ") " << schedule.getName() << endl;
		order++;
	}

	cout << "완료한 일정을 고르세요." << endl;

	int index;
	cin >> index;

	if (scheduleList.at(index - 1).is_done())
		cout << "이미 완료된 일정입니다." << endl;
	else {
		scheduleList.at(index - 1).done();
	}

	save();
}