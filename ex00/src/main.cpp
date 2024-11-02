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

int32_t	main(void)
{
	Bureaucrat	admin("admin", 1);
	Bureaucrat	steve("steve", 42);
	Bureaucrat	dumbass("dumbass", 150);
	Bureaucrat	*tmp = nullptr;

	std::cout << admin;
	std::cout << steve;
	std::cout << dumbass;

	try {
		admin.increaseGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	try {
		steve.increaseGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}
	try {
		dumbass.decreaseGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
	}

	std::cout << admin;
	std::cout << steve;
	std::cout << dumbass;

	try {
		tmp = new Bureaucrat("test", 0);
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
		delete tmp;
		tmp = nullptr;
	}
	if (tmp) {
		std::cout << *tmp;
		delete tmp;
	}
	try {
		tmp = new Bureaucrat("test", 200);
	} catch (std::exception &e) {
		std::cout << e.what() << "\n";
		delete tmp;
		tmp = nullptr;
	}
	if (tmp) {
		std::cout << *tmp;
		delete tmp;
	}
	
	return 0;
}
