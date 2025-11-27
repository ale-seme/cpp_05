#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {

    std::cout << "TESTING FORM DEFAULT CONSTRUCTOR" << std::endl;

    Form f1;
    std::cout << f1 << std::endl;

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING SUCCESSFUL FORM PARAMETERIZED CONSTRUCTOR" << std::endl;

    Form f2("Tax Form", false, 50, 25);
    std::cout << f2 << std::endl;

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING FORM COPY CONSTRUCTOR" << std::endl;
    Form f3(f2);
    std::cout << f3 << std::endl;

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING FORM ASSIGNMENT OPERATOR" << std::endl;
    Form f4("License", false, 100, 75);
    Form f2signed("Signed Tax form", true, 120, 3);
    std::cout << "Before: " << f4 << std::endl;
    std::cout << "Assigning now it to " << f2 << std::endl;
    f4 = f2signed;
    std::cout << "After: " << f4 << std::endl;

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING OVERLOAD OF THE << OPERATOR FOR FORM" << std::endl;
    std::cout << f2 << std::endl;

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING GETTERS OF THE FORM CLASS" << std::endl;

    std::cout << "getName -> " << f2.getName() << std::endl;
    std::cout << "isSigned -> " << (f2.isSigned() ? "yes" : "no") << std::endl;
    std::cout << "gradeToSign -> " << f2.gradeToSign() << std::endl;
    std::cout << "gradeToExecute -> " << f2.gradeToExecute() << std::endl;

    std::cout << "================================================" << std::endl;
    std::cout << "TESTING BUREAUCRAT SIGNING FORMS" << std::endl;
    
    Bureaucrat bob("Bob", 40);
    Bureaucrat alice("Alice", 60);
    
    std::cout << "\n" << bob << std::endl;
    std::cout << f2 << std::endl;
    bob.signForm(f2);
    std::cout << "Result after signing: " << (f2.isSigned() ? "Signed" : "Not signed") << std::endl;

    std::cout << "\n================================================" << std::endl;
    std::cout << "TESTING BUREAUCRAT WITH INSUFFICIENT GRADE" << std::endl;

    Form f5("High Security Form", false, 30, 20);
    std::cout << alice << std::endl;
    std::cout << f5 << std::endl;
    alice.signForm(f5);

    std::cout << "\n================================================" << std::endl;
    
    std::cout << "TESTING EXCEPTIONS DURING FORM CONSTRUCTION" << std::endl;
    std::cout << "================================================" << std::endl;

    try {
        std::cout << "Test 1: constructing a Form with gradeToSign 0 (too high)" << std::endl;
        Form f6("Invalid Form 1", false, 0, 50);
        std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 2: constructing a Form with gradeToExecute -1 (too high)" << std::endl;
        Form f7("Invalid Form 2", false, 50, -1);
        std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 3: constructing a Form with gradeToSign 151 (too low)" << std::endl;
        Form f8("Invalid Form 3", false, 151, 50);
        std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    try {
        std::cout << "\nTest 4: constructing a Form with gradeToExecute 200 (too low)" << std::endl;
        Form f9("Invalid form 4", false, 50, 200);
        std::cout << "SHOULD NOT BE DISPLAYED" << std::endl;
    }
    catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n================================================" << std::endl;
    std::cout << "TESTING EXCEPTIONS IN beSigned METHOD" << std::endl;
    std::cout << "================================================" << std::endl;

    Bureaucrat lowAlice("Alice low", 100);
    Form strictForm("Strict Form", false, 50, 25);

    try {
        std::cout << "Test 5: Bureaucrat with grade 100 trying to sign form requiring grade 50" << std::endl;
        std::cout << lowAlice << std::endl;
        std::cout << strictForm << std::endl;
        lowAlice.signForm(strictForm);
    }
    catch(const std::exception &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "\n================================================" << std::endl;
    std::cout << "TESTING SUCCESSFUL SIGNING SCENARIOS" << std::endl;
    std::cout << "================================================" << std::endl;

    Bureaucrat highAlice("HighGrade", 10);
    Form easyForm("Easy Form", false, 20, 30);
    
    std::cout << highAlice << std::endl;
    std::cout << easyForm << std::endl;
    highAlice.signForm(easyForm);
    std::cout << "After: " << easyForm << std::endl;

    std::cout << "\n================================================" << std::endl;
    std::cout << "TESTING EXTRA EDGE CASES" << std::endl;
    std::cout << "================================================" << std::endl;
    
    std::cout << "\nTrying to sign already signed form:" << std::endl;
    highAlice.signForm(easyForm);

    std::cout << "\n================================================" << std::endl;
    std::cout << "TESTING DESTRUCTORS FOR REMAINING OBJECTS" << std::endl;

}