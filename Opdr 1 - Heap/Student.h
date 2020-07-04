#pragma once
#include <vector>
#include "Persoon.h"
#include "Module.h"

class Module;

class Student :
    public Persoon
{
public:
    std::vector<Module*> modules = {};
    
    Student(std::string _naam);
    Student(std::string _naam, std::vector<Module*> _module);
    
    int getEC();
    void AddModule(Module* _module);
    void AddModules(std::vector<Module*> _modules);
    std::vector<Module*> getModules();
    void RemoveModule(Module* _module);
};

