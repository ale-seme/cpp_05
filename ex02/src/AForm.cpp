#include "AForm.hpp"
#include <string.h>

AForm::AForm(): _name("Default AForm"), _signed(false), _gradeToSign(1), _gradeToExecute(1), _target("default_target") {
    std::cout << "Default constructor called for AForm" << std::endl;
}

AForm::AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute, std::string target) :
    _name(name), _signed(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute), _target(target) {
        if (gradeToSign < 1) {
            throw GradeTooHighException("grade to sign too high");
        }
        else if (gradeToExecute < 1) {
            throw GradeTooHighException("grade to execute too high");
        }
        else if (gradeToSign > 150) {
            throw GradeTooLowException("grade to sign too low");
        }
        else if (gradeToExecute > 150) {
            throw GradeTooLowException("grade to execute too low");
        }
        std::cout << "Parameterize constructor called for " << _name << std::endl;
}

AForm::AForm(const AForm& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign),
    _gradeToExecute(other._gradeToExecute), _target(other._target) {
        std::cout << "Copy constructor for AForm " << _name << std::endl;
}

AForm& AForm::operator=(const AForm &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    std::cout << "Assignment operator for AForm " << _name << std::endl;
    return *this;
}

AForm::~AForm() {
    std::cout << "Destructor called for AForm " << _name << std::endl;
}

const std::string AForm::getName() const {
    return _name;
}

bool AForm::isSigned() const {
    return _signed;
}

int AForm::gradeToSign() const {
    return _gradeToSign;
}

int AForm::gradeToExecute() const {
    return _gradeToExecute;
}

const std::string AForm::getTarget() const {
    return _target;
}


std::ostream& operator<<(std::ostream& out, const AForm& f) {
    out << "Form Name: " 
        << f.getName()
        << ", Signed:"
        << (f.isSigned() ? "Signed" : "Not signed")
        << ", Grade to Sign: "
        << f.gradeToSign() << ", Grade to Execute: "
        << f.gradeToExecute() << ", Target: "
        << f.getTarget() << std::endl;
    return out;
}

void AForm::beSigned(const Bureaucrat& b) {
    if ( b.getGrade() > gradeToSign()) 
        throw GradeTooLowException("bureaucrat's grade too low to sign the form");
    else if (isSigned())
        throw FormAlreadySignedException("this form is already signed, it cannot be signed again");
    _signed = true;
}


void AForm::execute(Bureaucrat const & executor) const {
    if (!isSigned())
        throw(FormNotSignedException("this form is not signed yet, it cannot be executed"));
    if (executor.getGrade() > gradeToExecute())
    {
        throw(GradeTooLowException(
            executor.getName() + "grade is " + std::to_string(executor.getGrade()) 
            + "to execute Form of grade: " + std::to_string(gradeToExecute())
        ));
    }
    proceedToExecuteAction();
}

// Exception classes implementations

AForm::GradeTooHighException::GradeTooHighException(const std::string &msg): _errorMessage(msg) {}

const char* AForm::GradeTooHighException::what() const noexcept {
    return _errorMessage.c_str();
}


AForm::GradeTooLowException::GradeTooLowException(const std::string &msg): _errorMessage(msg) {}

const char* AForm::GradeTooLowException::what() const noexcept {
    return _errorMessage.c_str();
}

AForm::FormAlreadySignedException::FormAlreadySignedException(const std::string &msg): _errorMessage(msg) {}

const char* AForm::FormAlreadySignedException::what() const noexcept {
    return _errorMessage.c_str();
}

AForm::FormNotSignedException::FormNotSignedException(const std::string &msg): _errorMessage(msg) {}

const char* AForm::FormNotSignedException::what() const noexcept {
    return _errorMessage.c_str();
}
