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

	int order = 1;
	while (getline(fs, line)) {
		cout << order << ") " << line << endl;
		order++;
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

	view();
	cout << "�Ϸ��� ������ ������." << endl;

	int index;
	cin >> index;

	if (scheduleList.at(index - 1).is_done())
		cout << "�̹� �Ϸ�� �����Դϴ�." << endl;
	else {
		scheduleList.at(index - 1).done();
	}

	save();
}

void ToDoList::removeSchedule() {
	read();
	view();
	cout << "������ ������ ������.(0 �Է½� ����)." << endl;

	while (1) {
		int index;
		cin >> index;
		if (!cin)
			cout << "������ �Է����ּ���." << endl;
		else if (index > scheduleList.size() - 1)
			cout << "�ش� ������ �������� �ʽ��ϴ�." << endl;
		else if (index == 0) break;
		else {
			scheduleList.erase(scheduleList.begin() + index - 1);
			save();
		}
		view();
	}
}

void ToDoList::setPriority() {
	read();
	view();

	cout << "�켱������ ������ ������ ������(0 �Է� �� ����)." << endl;

	while (1) {
		int index;
		cin >> index;
		if (!cin) {
			cout << "������ �Է����ּ���." << endl;
			continue;
		}
		else if (index > scheduleList.size())
			cout << "�ش� ������ �������� �ʽ��ϴ�." << endl;
		else if (index == 0) break;
		else {
			selectUpAndDown(index);
			save();
		}
		view();
	}
}

void ToDoList::selectUpAndDown(int index) {
	cout << "�켱����\n1.���̱�\n2.���߱�" << endl;
	int upAndDown;
	cin >> upAndDown;

	if (!cin) {
		cout << "������ �Է����ּ���." << endl;
		return;
	}
	else if (upAndDown == 1)
		upPriority(index);
	else if (upAndDown == 2)
		downPriority(index);

}

void ToDoList::upPriority(int index) {
	if (index > scheduleList.size()) {
		cout << "�Է��� �߸� �Ǿ����ϴ�." << endl;
		return;
	}
	else if (index == 1) {
		cout << "�켱������ ���� ���� ������ �� �̻� �켱������ ���� �� �����ϴ�." << endl;
	}

	string task;

	task = scheduleList.at(index-1).getSchedule();
	Schedule schedule(task);
	scheduleList.erase(scheduleList.begin() + index - 1);
	scheduleList.insert(scheduleList.begin() + index - 2, schedule);
}

void ToDoList::downPriority(int index) {
	if (index > scheduleList.size()) {
		cout << "�Է��� �߸� �Ǿ����ϴ�." << endl;
		return;
	}
	else if (index == scheduleList.size()) {
		cout << "�켱������ ���� ���� ������ �� �̻� �켱������ ���� �� �����ϴ�." << endl;
	}

	string task;

	task = scheduleList.at(index - 1).getSchedule();
	Schedule schedule(task);
	scheduleList.erase(scheduleList.begin() + index - 1);
	scheduleList.insert(scheduleList.begin() + index , schedule);
}