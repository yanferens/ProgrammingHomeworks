#include "student.h"
#include <iostream>
#include <format>


using std::string;

Student::Student(std::string name, std::string groupID, int energy, int knowledgeLevel) : name(name), groupID(groupID), energy(energy), knowledgeLevel(knowledgeLevel) {
    std::cout << std::format("Student {} was created", name) << std::endl;
}
void Student::Eat() {
    this->energy++;
}
void Student::Sleep() {
    this->energy++;
}
bool Student::Study() {
    if (getEnergy() < 2) {
        return false;
    }
    this->knowledgeLevel++;
    this->energy--;
    return true;
}
ostream& operator<<(ostream& f, const Student& p) {
    f << std::format("Name: {}, groupID: {}, energy: {}, knowledgeLevel: {}", p.getName(), p.getGroupID(), p.getEnergy(), p.getKnowledgeLevel());
    return f;
}
Student createStudent(){
    std::string name;
    int energy;
    int knowledgeLevel;
    std::string groupID;
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter groupID: ";
    std::cin >> groupID;
    std::cout << "Enter energy: ";
    std::cin >> energy;
    std::cout << "Enter knowledgeLevel: ";
    std::cin >> knowledgeLevel;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        throw std::invalid_argument("Invalid input");
    }
    return Student(name, groupID, energy, knowledgeLevel);

}

