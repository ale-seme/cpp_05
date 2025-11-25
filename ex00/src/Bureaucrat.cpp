#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default Bureaucrat"), _grade(150) {
	std::cout << "Default constructor for a Bureaucrat" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	std::cout << "Parameterized constructor for " << _name << " with grade " << _grade << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Copy constructor for " << _name << " with grade " << _grade << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_grade = other._grade;
	}
	std::cout << "Assignment operator for " << _name << " with grade " << _grade << std::endl;
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor for " << _name << " with grade " << _grade << std::endl;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
		if (_grade <= 1)
			throw GradeTooHighException();
		_grade--;
}
void Bureaucrat::decrementGrade() {
	if (_grade >= 150)
		throw GradeTooLowException();
	_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept {
	return ("grade cannot be higher than 1");
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept {
	return ("grade cannot be lower than 150");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}