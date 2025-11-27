#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

    private:
        void proceedToExecuteAction() const override;
    
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string & target);
        ShrubberyCreationForm(const ShrubberyCreationForm & other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm & other);
        ~ShrubberyCreationForm();
};