#include "Student.h"
#include "Module.h"

Student::Student(std::string _naam)
{
	naam = _naam;
}

Student::Student(std::string _naam, std::vector<Module*> _modules)
{
	naam = _naam;
	modules = _modules;
}

int Student::getEC()
{
	int ecTotaal = 0;
	for (size_t i = 0; i < modules.size(); i++)
	{
		ecTotaal += modules[i]->getEC();
	}

	return ecTotaal;
}

void Student::AddModule(Module* _module)
{
	modules.push_back(_module);
}

void Student::AddModules(std::vector<Module*> _modules)
{
	for (size_t i = 0; i < _modules.size(); i++)
	{
		modules.push_back(_modules[i]);
	}
}

std::vector<Module*> Student::getModules()
{
	return modules;
}

void Student::RemoveModule(Module* _module)
{
	std::vector<Module*>::iterator iterator;
	iterator = std::find(modules.begin(), modules.end(), _module);

	modules.erase(iterator);
}
