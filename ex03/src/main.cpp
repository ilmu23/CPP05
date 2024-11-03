// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<main.cpp>>

#include <iostream>
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int32_t	main(void)
{
	Intern		who;
	Bureaucrat	admin("Admin", 1);
	Bureaucrat	steve("Steve", 11);
	Bureaucrat	dumbass("Dumbass", 145);
	AForm		*form;

	std::cout << admin;
	std::cout << steve;
	std::cout << dumbass;

	form = who.makeForm("shrubbery creation", "01");
	if (!form)
		return 1;
	dumbass.executeForm(*form);
	dumbass.signForm(*form);
	dumbass.executeForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("shrubbery creation", "02");
	if (!form)
		return 1;
	dumbass.signForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("shrubbery creation", "03");
	if (!form)
		return 1;
	dumbass.signForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("shrubbery creation", "04");
	if (!form)
		return 1;
	dumbass.signForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("shrubbery creation", "05");
	if (!form)
		return 1;
	dumbass.signForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("shrubbery creation", "06");
	if (!form)
		return 1;
	dumbass.signForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("shrubbery creation", "07");
	if (!form)
		return 1;
	dumbass.signForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("shrubbery creation", "08");
	if (!form)
		return 1;
	dumbass.signForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("shrubbery creation", "09");
	if (!form)
		return 1;
	dumbass.signForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("shrubbery creation", "10");
	if (!form)
		return 1;
	dumbass.signForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("robotomy request", "Dumbass");
	if (!form)
		return 1;
	dumbass.signForm(*form);
	steve.signForm(*form);
	steve.executeForm(*form);

	delete form;
	form = who.makeForm("presidential pardon", "Dumbass");
	if (!form)
		return 1;
	steve.signForm(*form);
	steve.executeForm(*form);
	admin.executeForm(*form);

	delete form;
	form = who.makeForm("infinite money glitch permit", "Who");

	return 0;
}
