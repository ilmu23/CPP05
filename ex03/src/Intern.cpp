// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Intern.cpp>>

#include <iostream>
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

static const std::string	_formtypes[_FORM_COUNT] = {
	"robotomy request",
	"shrubbery creation",
	"presidential pardon"
};

Intern::Intern(void) {}

Intern::~Intern(void) {}

// misc

AForm	*Intern::makeForm(const std::string &form, const std::string &target) const
{
	size_t	i;

	for (i = 0; i < _FORM_COUNT; i++)
		if (_formtypes[i] == form)
			break ;
	switch (i)
	{
		case 0:
			std::cout << "Intern creates " << form << " form.\n"; 
			return new RobotomyRequestForm(target);
		case 1:
			std::cout << "Intern creates " << form << " form.\n"; 
			return new ShrubberyCreationForm(target);
		case 2:
			std::cout << "Intern creates " << form << " form.\n"; 
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Form " << form  << " doesn't exist.\n";
			return nullptr;
	}
}
