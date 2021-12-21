#include <iostream>
#include <vector>
#include <fstream>

#include "Employee.h"
#include "Programmer.h"
#include "Tester.h"
#include "Manager.h"
#include "Utils.h"

void showMenu() {
	cout << "-----------------------Menu----------------------" << '\n';
	cout << "1. Add employee" << '\n';
	cout << "2. Edit employee" << '\n';
	cout << "3. Remove employee" << '\n';
	cout << "4. Sort employee by name" << '\n';
	cout << "5. Show all employees" << '\n';
	cout << "0. Exit" << '\n';
	cout << "--------------------------------------------------" << '\n';
	cout << "Please choose: ";
}

void showAll(vector<Employee*> list) {
	for (auto e : list) {
		e->show();
	}
}

int main()
{
	//Employee* e{new Employee()};

	//e->input();

	//e->show();

	//Employee* p{ new Programmer() };
	//Employee* t{ new Tester{} };
	//Employee* m{ new Manager{} };
	//p->input();
	//p->show();

	//vector<int> numbers{ 1, 2, 3 };
	//cout << numbers[0] << '\n';
	//cout << numbers.at(1) << '\n';
	//numbers.push_back(4);
	//cout << numbers.at(3);

	//vector<Employee*> list{};

	//list.push_back(m);
	//list.push_back(p);
	//list.push_back(t);

	//for (int i{ 0 }; i < list.size(); ++i) {
	//    list.at(i)->input();
	//}

	//for (Employee* e : list) {
	//for (auto e : list) {
	//    e->show();
	//}




	vector<Employee*> list{};

	ifstream fileIn{ "input.txt" };

	// doc du lieu tu file
	string line;
	while (getline(fileIn, line)) {

		auto vec = Utils::split(line, ",");

		if (vec.at(0) == "1") {
			list.push_back(new Programmer{ stoi(vec.at(1)), vec.at(2) });
		}
		else if (vec.at(0) == "2") {
			list.push_back(new Tester{ stoi(vec.at(1)), vec.at(2) });
		}
		else if (vec.at(0) == "3") {
			list.push_back(new Manager{ stoi(vec.at(1)), vec.at(2) });
		}
	}

	//

	//for (auto e : list) {
	//	e->show();
	//}

	int choose;
	bool exit{ false };

	showMenu();
	while (true) {

		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Add employee" << '\n';
			break;
		case 2:
			cout << "Edit employee" << '\n';
			break;
		case 3:
			cout << "Remove employee" << '\n';
			break;
		case 4:
			cout << "Sort by name" << '\n';
			break;
		case 5:
			cout << "Show all employees" << '\n';
			showAll(list);
			break;
		case 0:
			cout << "Exit" << '\n';
			exit = true;
			break;
		}
		if (exit) {
			break;
		}
		showMenu();
	}

}

/* 25/11/2021
Quản lý nhân viên
- Có danh sách các nhân viên
- Xem, sửa thông tin của các nhân viên
- Thêm, xóa nhân viên
- Sắp xếp, tìm kiếm nhân viên (tên, lương,...)
*/

/*
-- Nhân viên: Programmer, Tester, Manager, ... => base class Employee
-- List (array) -> vector<Employee *>
-- File io
-- Logics: sort, search, ...
-- Giao diện: console, menu
*/

/*
-- Employee: id, name, email, phone,... // doWork(), ...
-- subclasses: Programmer, Tester, Manager (public Employee)
*/

// 30/11/2021: getters + setters + subclasses

//2/12/2021
// Programmer: programming language
// Teseter: category (database, network, ...)

// Manager: yoe (nam cong tac)


/*
9/12/2021
- Add employee:
	+ menu: chọn loại nv (pr, t, m)
	+ if... => new.. => list.push_back()
*/