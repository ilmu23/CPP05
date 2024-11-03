// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<AForm.cpp>>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, const uint8_t &s_grade, const uint8_t &e_grade):
	_name(name), _signed(false), _s_grade(s_grade), _e_grade(e_grade)
{
	if (_MAX(_s_grade, _e_grade) > _GRADE_MAX)
		throw AForm::GradeTooLowException();
	if (_MIN(_s_grade, _e_grade) < _GRADE_MIN)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm &copy): _name(copy.getName()), _signed(copy.getSigned()),
	_s_grade(copy.getSignGrade()), _e_grade(copy.GetExecGrade()) {}

AForm::~AForm(void) {}

// overload

std::ostream	&operator<<(std::ostream &stream, const AForm &fm)
{
	stream << "Form " << fm.getName() << ": Signed: " << fm.getSigned();
	stream << ", Signing grade: " << (uint16_t)fm.getSignGrade();
	stream << ", Execution grade: " << (uint16_t)fm.GetExecGrade() << ".\n";
	return stream;
}

// get

const std::string	&AForm::getName(void) const
{
	return this->_name;
}

const bool	&AForm::getSigned(void) const
{
	return this->_signed;
}

const uint8_t	&AForm::getSignGrade(void) const
{
	return this->_s_grade;
}

const uint8_t	&AForm::GetExecGrade(void) const
{
	return this->_e_grade;
}

// misc

uint8_t	AForm::isExecutable(const Bureaucrat &bc) const
{
	if (!this->getSigned())
		throw AForm::FormNotSignedException();
	if (bc.getGrade() > this->GetExecGrade())
		throw AForm::GradeTooLowException();
	return 1;
}

void	AForm::beSigned(const Bureaucrat &bc)
{
	if (bc.getGrade() > this->getSignGrade())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

// exception

const char	*AForm::GradeTooHighException::what(void) const noexcept
{
	return "Grade too high";
}

const char	*AForm::GradeTooLowException::what(void) const noexcept
{
	return "Grade too low";
}

const char	*AForm::FormNotSignedException::what(void) const noexcept
{
	return "Form is not signed";
}
