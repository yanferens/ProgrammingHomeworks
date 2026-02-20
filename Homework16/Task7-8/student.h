#pragma once
#include <string>
using std::ostream;


class Student {
private:
    std::string name;
    std::string groupID;
    int energy = 0;
    int knowledgeLevel = 0;
    public:
    int getEnergy() const {return energy;};
    std::string getName() const {return name;};
    std::string getGroupID() const {return groupID;};
    int getKnowledgeLevel() const {return knowledgeLevel;};
    Student(std::string name, std::string groupID, int energy, int knowledgeLevel);
    void Eat();
    void Sleep();
    bool Study();
};
std::ostream &operator<<(std::ostream &f, const Student &p);
Student createStudent();