#include "Form.hpp"
#include <string.h>

Form::Form(): _name("Default Form"), _signed(false), _gradeToSign(1), _gradeToExecute(1) {
    std::cout << "Default constructor called for Form" << std::endl;
}

Form::Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute) :
    _name(name), _signed(isSigned), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
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

Form::Form(const Form& other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
    std::cout << "Copy constructor for Form " << _name << std::endl;
}

Form& Form::operator=(const Form &other) {
    if (this != &other) {
        _signed = other._signed;
    }
    std::cout << "Assignment operator for Form " << _name << std::endl;
    return *this;
}

Form::~Form() {
    std::cout << "Destructor called for Form " << _name << std::endl;
}

const std::string Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::gradeToSign() const {
    return _gradeToSign;
}

int Form::gradeToExecute() const {
    return _gradeToExecute;
}


std::ostream& operator<<(std::ostream& out, const Form& f) {
    out << "Form Name: " 
        << f.getName()
        << ", Signed:"
        << (f.isSigned() ? "Signed" : "Not signed")
        << ", Grade to Sign: "
        << f.gradeToSign() << ", Grade to Execute: "
        << f.gradeToExecute() << std::endl;
    return out;
}

void Form::beSigned(const Bureaucrat& b) {
    if ( b.getGrade() > gradeToSign()) 
        throw GradeTooLowException("bureaucrat's grade too low to sign the form");
    else if (isSigned())
        throw FormAlreadySignedException("this form is already signed, it cannot be signed again");
    _signed = true;
}

Form::GradeTooHighException::GradeTooHighException(const std::string &msg): _errorMessage(msg) {}

const char* Form::GradeTooHighException::what() const noexcept {
    return _errorMessage.c_str();
}


Form::GradeTooLowException::GradeTooLowException(const std::string &msg): _errorMessage(msg) {}

const char* Form::GradeTooLowException::what() const noexcept {
    return _errorMessage.c_str();
}

Form::FormAlreadySignedException::FormAlreadySignedException(const std::string &msg): _errorMessage(msg) {}

const char* Form::FormAlreadySignedException::what() const noexcept {
    return _errorMessage.c_str();
}
