#include "Module.h"
#include <iostream>

Module::Module(std::string _name)
{
    name = _name;
}

Module::Module(std::string _name, int _ec)
{
    name = _name;
    ec = _ec;
}

std::string Module::getName()
{
    return name;
}

void Module::setEC(int _ec)
{
    ec = _ec;
}

int Module::getEC()
{
    return ec;
}

Docent Module::getTeacher()
{
    return docent;
}

void Module::setTeacher(Docent _docent)
{
    docent = _docent;
}

std::vector<std::string> Module::getStudentsNames()
{
    std::vector<std::string> studentNames;
    for (size_t i = 0; i < students.size(); i++)
    {
        studentNames.push_back(students[i]->getName());
    }
    return studentNames;
}

void Module::setStudents(std::vector<Student*> _students)
{
    for (size_t i = 0; i < _students.size(); i++)
    {
        _students[i]->modules.push_back(this);
    }
    students = _students;
}

void Module::removeStudent(Student* _student)
{
    std::vector<Student*>::iterator iterator;
    iterator = std::find(students.begin(), students.end(), _student);
    if (iterator == students.end()) {
        std::cout << "Tried to remove student " + _student->getName() + ", but this student does not follow the module " + this->getName() + '\n';
        return;
    }

    students.erase(iterator);
    _student->RemoveModule(this);
}
