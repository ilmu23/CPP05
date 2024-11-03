// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<main.cpp>>

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int32_t	main(void)
{
	Bureaucrat	admin("Admin", 1);
	Bureaucrat	dumbass("Dumbass", 150);
	Form		fdf("Fire dumbass form", 42, 21);

	std::cout << admin;
	std::cout << dumbass;
	std::cout << fdf;
	
	dumbass.signForm(fdf);
	std::cout << fdf;

	admin.signForm(fdf);
	std::cout << fdf;

	return 0;
}
