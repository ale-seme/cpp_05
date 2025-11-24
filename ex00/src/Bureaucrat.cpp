#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150) {
    std::cout << "Default constructor for Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
    if (grade < 1 || grade > 150) {
        throw std::out_of_range("Grade must be between 1 and 150");
    }
    std::cout << "Parameterized constructor for Bureaucrat " << _name << " with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
    std::cout << "Copy constructor for Bureaucrat " << _name << " with grade " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        _grade = other._grade;
    }
    std::cout << "Assignment operator for Bureaucrat " << _name << " with grade " << _grade << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Destructor for Bureaucrat " << _name << " with grade " << _grade << std::endl;
}