#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    {
        try
        {
            Form form0("A99", 0, 5);
            std::cout << form0 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "\n ---------------------- \n\n";

    {
        try
        {
            Bureaucrat val("Val", 15);
            Form form("b58", 20, 45);
            std::cout << val << std::endl;
            std::cout << form << std::endl;
            val.signForm(form);
            std::cout << form << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }

    std::cout << "\n ---------------------- \n\n";

    {
        try
        {
            Bureaucrat baptiste("baptiste", 35);
            Form form2("c45", 20, 45);
            std::cout << baptiste << std::endl;
            std::cout << form2 << std::endl;
            baptiste.signForm(form2);
            std::cout << form2 << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    return 0;
}