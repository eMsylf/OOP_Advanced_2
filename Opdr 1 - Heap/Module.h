#pragma once
#include <string>
#include <vector>
#include "Docent.h"
#include "Student.h"

class Student;

class Module
{
public:
	// Variables
	std::string name;
	int ec;
	Docent docent;
	std::vector<Student*> students;

	// Constructors
	Module(std::string _name);
	Module(std::string _name, int _ec);

	// Functions
	std::string getName();
	void setEC(int _ec);
	int getEC();
	Docent getTeacher();
	void setTeacher(Docent _docent);
	std::vector<std::string> getStudentsNames();
	void setStudents(std::vector<Student*> _students);
	void removeStudent(Student* _student);
};

