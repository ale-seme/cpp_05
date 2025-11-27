#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("DefaultShrubberyCreationForm", false, 145, 137, "Default Target") {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target): 
    AForm("ShrubberyCreationForm", false, 145, 137, target) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm & other) {
    AForm::operator=(other);
    return *this;
} ;

ShrubberyCreationForm::~ShrubberyCreationForm() {};

