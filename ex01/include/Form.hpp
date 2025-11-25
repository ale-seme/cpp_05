#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>


class Form {

    private:
        std::string _name;
        bool _singed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        Form();
        Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();

        class GradeTooHighException : public std::exception {
            const char* what() const noexcept override;

        };
        class GradeTooLowException : public std::exception {
            const char* what() const noexcept override;
        };

};

std::ostream& operator<<(std::ostream& out, const Form& f);


#endif