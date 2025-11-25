#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {

	private: 
		std::string const _name;
		int _grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception{
			public:
				const char* what() const noexcept override;
		};
		class GradeTooLowException : public std::exception{
			public:
				const char* what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b);

#endif