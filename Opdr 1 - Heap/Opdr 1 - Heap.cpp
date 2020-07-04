// Opdr 1 - Heap.cpp
// Bob Jeltes

#include <iostream>
#include <vector>
#include "Module.h"
#include "Docent.h"
#include "Student.h"
#include "TypeSizes.h"

void CreateTeacherList(std::vector<Docent*>& teacherList, std::vector<std::string> teacherNames);
void NamesToConsole(std::vector<Docent*> vector);
void CreateStudentList(std::vector<Student*>& studentList, std::vector<std::string> studentNames);
void NamesToConsole(std::vector<Student*> vector);
void CreateModuleList(std::vector<Module*>& modules, std::vector<std::string> moduleNames);
void AutoAssignTeachersToModules(std::vector<Module*> modules, std::vector<Docent*> teachers);
void NamesToConsole(std::vector<Module*> modules, bool includeTeachers, bool includeStudentNames);
void ShowECPerStudent(std::vector<Student*> students);


int main()
{
    //std::cout << "Hello World!\n";

    // MODULES
    Module* ITTT = new Module("ITTT", 5);
    Module* ECTTP = new Module("ECTTP", 5);
    Module* OBOPB = new Module("OBOPB", 5);

    // TEACHERS (3)
    Docent* PeterDeVries = new Docent("Peter De Vries");
    Docent* JanBoer = new Docent("Jan Boer");
    Docent* FredVanVeen = new Docent("Fred van Veen");

    // STUDENTS (10)
    Student* Pietje = new Student("Pietje", {ITTT, ECTTP});
    Student* Jantje = new Student("Jantje", { ITTT, ECTTP });
    Student* Maaike = new Student("Maaike", { ITTT, ECTTP });
    Student* Frans= new Student("Frans", { ITTT, ECTTP });
    Student* Julia = new Student("Julia", { ITTT, ECTTP });
    Student* Lisa = new Student("Lisa", { ITTT, ECTTP });
    Student* Milou = new Student("Milou", { ITTT, ECTTP });
    Student* Brendan = new Student("Brendan", { ITTT, ECTTP });
    Student* Karim = new Student("Karim", { ITTT, ECTTP });
    Student* Arvid = new Student("Arvid", { ITTT, ECTTP });

    std::vector<Student*> students = {Pietje, Jantje, Maaike, Frans, Julia, Lisa, Milou, Brendan, Karim, Arvid};

    ITTT->setTeacher(*PeterDeVries);
    ECTTP->setTeacher(*JanBoer);
    OBOPB->setTeacher(*FredVanVeen);

    ITTT->setStudents({ Pietje, Jantje, Maaike, Karim });
    ECTTP->setStudents({ Frans, Julia, Lisa, Pietje});
    OBOPB->setStudents({ Milou, Brendan, Karim, Arvid, Maaike });


    std::cout << "1) Print een lijst van modules, met docenten & studenten\n";
    NamesToConsole({ITTT, ECTTP, OBOPB}, true, true);


    std::cout << "\n2) Toon totaal EC per student\n";
    ShowECPerStudent(students);


    std::cout << "\n3) Wijzig EC van 1 module: toon totaal EC per student\n";
    ITTT->setEC(13);
    ShowECPerStudent(students);

    std::cout << "\n4) Verwijder student uit module, & toon lijst opnieuw\n";
    ITTT->removeStudent(Pietje);
    ShowECPerStudent(students);



    //---------- Vector-based initiation
    //std::vector<Docent*> teachers;
    //CreateTeacherList(teachers, { "Peter de Vries", "Jan Boer", "Fred van Veen" });
    //std::cout << "-------------\nTeachers: " << '\n';
    //NamesToConsole(teachers);

    //
    //std::vector<Student*> students;
    //CreateStudentList(students, { "Pietje", "Jantje", "Maaike", "Frans", "Julia", "Lisa", "Milou", "Brendan", "Karim", "Arvid" });
    //std::cout << "-------------\nStudents: " << '\n';
    //NamesToConsole(students);

    //std::vector<Module*> modules;
    //CreateModuleList(modules, { "ITTT", "ECTTP", "OBOPB" });
    //AutoAssignTeachersToModules(modules, teachers);
    //NamesToConsole(modules, true);

    //--------- Type size experiment
    //TypeSizes::DisplayTypeSizes();
}

void CreateTeacherList(std::vector<Docent*>& teacherList, std::vector<std::string> teacherNames)
{
    for (size_t i = 0; i < teacherNames.size(); i++)
    {
        teacherList.push_back(new Docent(teacherNames[i]));
    }
}

void CreateStudentList(std::vector<Student*>& studentList, std::vector<std::string> studentNames) {
    for (size_t i = 0; i < studentNames.size(); i++)
    {
        studentList.push_back(new Student(studentNames[i]));
    }
}

void CreateModuleList(std::vector<Module*>& modules, std::vector<std::string> moduleNames) {

    for (size_t i = 0; i < moduleNames.size(); i++)
    {
        modules.push_back(new Module(moduleNames[i]));
    }
}

void AutoAssignTeachersToModules(std::vector<Module*> modules, std::vector<Docent*> teachers) {
    for (size_t i = 0; i < modules.size(); i++)
    {
        modules[i]->setTeacher(*teachers[i]);
    }
}

void NamesToConsole(std::vector<Docent*> vector)
{
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i]->getName() << '\n';
    }
}

void NamesToConsole(std::vector<Student*> vector) {
    for (size_t i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i]->getName() << '\n';
    }
}

void NamesToConsole(std::vector<Module*> modules, bool includeTeacherNames, bool includeStudentNames) {
    for (size_t i = 0; i < modules.size(); i++)
    {
        std::string outputString;
        outputString += "\nModule naam: " + modules[i]->getName() + '\n';
        if (includeTeacherNames) outputString += " Docent: " + modules[i]->getTeacher().getName() + '\n';
        if (includeStudentNames) {
            outputString += " Studenten:\n";
            std::vector<std::string> studentNames = modules[i]->getStudentsNames();
            int iterator = 1;
            for (size_t i = 0; i < studentNames.size(); i++)
            {
                // GAAT PRIMA
                std::string stringizedIterator = std::to_string(iterator);
                outputString += "  " + stringizedIterator + ". " + studentNames[i] + '\n';
                // GEEFT ISSUES
                //outputString += "  " + std::to_string(i)  + ". " + studentNames[i] + '\n';
                iterator++;
            }
        }
        std::cout << outputString << '\n';
    }
}

void ShowECPerStudent(std::vector<Student*> students) {
    for (size_t i = 0; i < students.size(); i++)
    {
        std::cout<< /*"Student: " << */students[i]->getName() << " heeft "<< students[i]->getEC() << " EC\n";
    }
}
