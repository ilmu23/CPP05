// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Bureaucrat.cpp>>

#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, const uint8_t &grade): _name(name), _grade(grade) 
{
	if (this->_grade > _GRADE_MAX)
		throw Bureaucrat::GradeTooLowException();
	if (this->_grade < _GRADE_MIN)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.getName()), _grade(copy.getGrade()) {}

Bureaucrat::~Bureaucrat(void) {}

// overload

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bc)
{
	stream << bc.getName() << ", bureaucrat grade " << (uint16_t)bc.getGrade() << ".\n";
	return stream;
}

// get

const std::string	&Bureaucrat::getName(void) const
{
	return this->_name;
}

const uint8_t	&Bureaucrat::getGrade(void) const
{
	return this->_grade;
}

//misc

void	Bureaucrat::signForm(Form &fm)
{
	try {
		fm.beSigned(*this);
		std::cout << this->getName() << " signed form " << fm.getName() << ".\n";
	} catch (std::exception &e) {
		std::cout << this->getName() << " couldn't sign ";
		std::cout << fm.getName() << " because " << e.what() << ".\n";
	}
}

void	Bureaucrat::increaseGrade(void)
{
	if (this->_grade == _GRADE_MIN)
		throw GradeTooHighException();
	this->_grade--;
}

void	Bureaucrat::decreaseGrade(void)
{
	if (this->_grade == _GRADE_MAX)
		throw GradeTooLowException();
	this->_grade++;
}

// exception

const char	*Bureaucrat::GradeTooHighException::what(void) const noexcept
{
	return "Grade too high";
}

const char	*Bureaucrat::GradeTooLowException::what(void) const noexcept
{
	return "Grade too low";
}
