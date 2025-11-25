#include "Bureaucrat.hpp"

int main () {

    std::cout << "TESTING BUREAUCRAT DEFAULT CONTRUCTOR" << std::endl;

    Bureaucrat b1;

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING SUCCESSFULL BUREAUCRAT PARAMETERIZED CONSTRUCTOR" << std::endl;

    Bureaucrat b2("Bob", 42);

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING BUREAUCRAT COPY CONSTRUCTOR" << std::endl;
    Bureaucrat b3(b2);

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING BUREAUCRAT ASSIGNMENT OPERATOR" << std::endl;
    Bureaucrat b4("Alberto", 30);
    b4 = b2;
    std::cout << b4 << std::endl;

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING OVERLOAD OF THE << OPERATOR FOR BUREAUCRAT" << std::endl;
    std::cout << b2 << std::endl;

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING GETTERS OF THE BURECREAUT CLASS" << std::endl;

    std::cout << "getName -> " << b2.getName() << std::endl;
    std::cout << "getGrade -> " << b2.getGrade() << std::endl;

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING INCREMENT GRADE" << std::endl;
    
    std::cout << b4 << std::endl;
    b4.incrementGrade();
    std::cout << b4 << std::endl;

    std::cout << "================================================" << std::endl;

    std::cout << "TESTING DECREMENT GRADE" << std::endl;
    std::cout << b4 << std::endl;
    b4.decrementGrade();
    std::cout << b4 << std::endl;

    std::cout << "================================================" << std::endl;
    
    std::cout << "TESTING EXCEPTIONS DURING CONSTRUCTION" << std::endl;
    std::cout << "================================================" << std::endl;

    try {
        std::cout << "Test 1: constructing a Bureaucrat with Grade 0 (too high)" << std::endl;
        Bureaucrat b5("Monique", 0);
        std::cout << b5 << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 2: constructing a Bureaucrat with Grade -1 (too high)" << std::endl;
        Bureaucrat b6("Pierre", -1);
        std::cout << b6 << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 3: constructing a Bureaucrat with Grade 151 (too low)" << std::endl;
        Bureaucrat b7("Marie", 151);
        std::cout << b7 << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n================================================" << std::endl;
    std::cout << "TESTING EXCEPTIONS IN METHODS" << std::endl;
    std::cout << "================================================" << std::endl;

    Bureaucrat b8("Carlos", 150);
    Bureaucrat b9("Carlitos", 1);

    std::cout << "\n";

    try {
        std::cout << "Test 4:" << std::endl;
        std::cout << "Before: " << b8 << std::endl<< "\n";
        std::cout << "Decrementing grade 150 (too low)" << std::endl;
        b8.decrementGrade();
        std::cout << "After: " << b8 << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 5" << std::endl;
        std::cout << "Before: " << b9 << std::endl;
        std::cout << "Increment grade 1" << std::endl;
        b9.incrementGrade();
        std::cout << "After: " << b9 << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n================================================" << std::endl;
    std::cout << "TESTING DESTRUCTORS FOR REMAINING BUREAUCRATS" << std::endl;

}