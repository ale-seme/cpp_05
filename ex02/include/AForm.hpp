#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class AForm {

    private:
        std::string const _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;
        
        virtual void proceedToExecuteAction() const = 0;

    protected:
        std::string _target;

    public:
        AForm();
        AForm(std::string name, bool isSigned, int gradeToSign, int gradeToExecute, std::string target);
        AForm(const AForm &other);
        AForm& operator=(const AForm &other);
        virtual ~AForm();

        const std::string getName() const;
        bool isSigned() const;
        int gradeToSign() const;
        int gradeToExecute() const;
        const std::string getTarget() const;

        void beSigned(const Bureaucrat& b);
        void execute(Bureaucrat const & executor) const;
        
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
        class FormNotSignedException : public std::exception {
            public:
                FormNotSignedException(const std::string &msg);
                const char* what() const noexcept override;
            private:
                std::string _errorMessage;
        }
};

std::ostream& operator<<(std::ostream& out, const AForm& f);


#endif