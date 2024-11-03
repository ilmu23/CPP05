// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<RobotomyRequestForm.cpp>>

#include <random>
#include <iostream>
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("Robotomy Request Form", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):
	AForm(copy), _target(copy.getTarget()) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

// get

const std::string	&RobotomyRequestForm::getTarget(void) const
{
	return this->_target;
}

// misc

void	RobotomyRequestForm::execute(const Bureaucrat &bc) const
{
	std::random_device	rand;

	if (this->isExecutable(bc)) {
		std::cout << "*LOUD DRILLING NOISES*\n";
		if (rand() & 1)
			std::cout << "Robotomy on " << this->getTarget() << " succeeded\n";
		else
			std::cout << "Robotomy on " << this->getTarget() << " failed\n";
	}
}
