// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Form.cpp>>

#include "Form.hpp"

Form::Form(const std::string &name, const uint8_t &s_grade, const uint8_t &e_grade):
	_name(name), _signed(false), _s_grade(s_grade), _e_grade(e_grade)
{
	if (_MAX(_s_grade, _e_grade) > _GRADE_MAX)
		throw Form::GradeTooLowException();
	if (_MIN(_s_grade, _e_grade) < _GRADE_MIN)
		throw Form::GradeTooHighException();
}

Form::Form(const Form &copy): _name(copy.getName()), _signed(copy.getSigned()),
	_s_grade(copy.getSignGrade()), _e_grade(copy.GetExecGrade()) {}

Form::~Form(void) {}

// overload

std::ostream	&operator<<(std::ostream &stream, const Form &fm)
{
	stream << "Form " << fm.getName() << ": Signed: " << fm.getSigned();
	stream << ", Signing grade: " << (uint16_t)fm.getSignGrade();
	stream << ", Execution grade: " << (uint16_t)fm.GetExecGrade() << ".\n";
	return stream;
}

// get

const std::string	&Form::getName(void) const
{
	return this->_name;
}

const bool	&Form::getSigned(void) const
{
	return this->_signed;
}

const uint8_t	&Form::getSignGrade(void) const
{
	return this->_s_grade;
}

const uint8_t	&Form::GetExecGrade(void) const
{
	return this->_e_grade;
}

// misc

void	Form::beSigned(const Bureaucrat &bc)
{
	if (bc.getGrade() > this->getSignGrade())
		throw Form::GradeTooLowException();
	this->_signed = true;
}

// exception

const char	*Form::GradeTooHighException::what(void) const noexcept
{
	return "Grade too high";
}

const char	*Form::GradeTooLowException::what(void) const noexcept
{
	return "Grade too low";
}
