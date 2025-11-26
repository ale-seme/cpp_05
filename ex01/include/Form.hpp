#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>


class Form {

    private:
        std::string const _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        Form();
        Form(std::string name, bool isSigned, int gradeToSign, int gradeToExecute);
        Form(const Form &other);
        Form& operator=(const Form &other);
        ~Form();

        const std::string getName() const;
        bool isSigned() const;
        int gradeToSign() const;
        int gradeToExecute() const;

        void beSigned(const Bureaucrat& b);
        
        class GradeTooHighException : public std::exception {
            public:
                GradeTooHighException(const std::string &msg);
                const char* what() const noexcept override;
            private:
                std::string _errorMessage;
        };
        class GradeTooLowException : public std::exception {
            public:
                GradeTooLowException(const std::string &msg);
                const char* what() const noexcept override;
            private:
                std::string _errorMessage;
        };
        class FormAlreadySignedException : public std::exception {
            public:
                FormAlreadySignedException(const std::string &msg);
                const char* what() const noexcept override;
            private:
                std::string _errorMessage;
        };

};

std::ostream& operator<<(std::ostream& out, const Form& f);


#endif