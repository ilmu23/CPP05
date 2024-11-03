// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<main.cpp>>

#include <iostream>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int32_t	main(void)
{
	Bureaucrat				admin("Admin", 1);
	Bureaucrat				steve("Steve", 11);
	Bureaucrat				dumbass("Dumbass", 145);
	RobotomyRequestForm		rrf("Dumbass");
	ShrubberyCreationForm	scf1("1");
	ShrubberyCreationForm	scf2("2");
	ShrubberyCreationForm	scf3("3");
	ShrubberyCreationForm	scf4("4");
	ShrubberyCreationForm	scf5("5");
	ShrubberyCreationForm	scf6("6");
	ShrubberyCreationForm	scf7("7");
	ShrubberyCreationForm	scf8("8");
	ShrubberyCreationForm	scf9("9");
	ShrubberyCreationForm	scf10("10");
	PresidentialPardonForm	ppf("Dumbass");

	std::cout << admin;
	std::cout << steve;
	std::cout << dumbass;

	dumbass.executeForm(scf1);

	dumbass.signForm(scf1);
	dumbass.signForm(scf2);
	dumbass.signForm(scf3);
	dumbass.signForm(scf4);
	dumbass.signForm(scf5);
	dumbass.signForm(scf6);
	dumbass.signForm(scf7);
	dumbass.signForm(scf8);
	dumbass.signForm(scf9);
	dumbass.signForm(scf10);

	dumbass.executeForm(scf1);
	steve.executeForm(scf1);
	steve.executeForm(scf2);
	steve.executeForm(scf3);
	steve.executeForm(scf4);
	steve.executeForm(scf5);
	steve.executeForm(scf6);
	steve.executeForm(scf7);
	steve.executeForm(scf8);
	steve.executeForm(scf9);
	steve.executeForm(scf10);

	dumbass.signForm(rrf);
	steve.signForm(rrf);
	steve.executeForm(rrf);

	steve.signForm(ppf);
	steve.executeForm(ppf);
	admin.executeForm(ppf);

	return 0;
}
