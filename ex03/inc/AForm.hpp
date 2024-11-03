// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<AForm.hpp>>

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <cstdint>
# include <ostream>
# include <exception>
# include "Bureaucrat.hpp"

# define _MAX(x, y)	((x > y) ? x : y)
# define _MIN(x, y)	((x < y) ? x : y)

class AForm
{
	private:

		const std::string	_name;
		bool				_signed;
		const uint8_t		_s_grade;
		const uint8_t		_e_grade;

	public:

		AForm(void) = delete;
		AForm(const std::string &name, const uint8_t &s_grade, const uint8_t &e_grade);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &copy) = delete;
		virtual ~AForm(void);

		// get

		const std::string	&getName(void) const;
		const bool			&getSigned(void) const;
		const uint8_t		&getSignGrade(void) const;
		const uint8_t		&GetExecGrade(void) const;

		// misc

		uint8_t			isExecutable(const Bureaucrat &bc) const;
		void			beSigned(const Bureaucrat &bc);
		virtual void	execute(const Bureaucrat &bc) const = 0;

		// exception

		class GradeTooHighException: public std::exception {
			const char	*what(void) const noexcept;
		};
		class GradeTooLowException: public std::exception {
			const char	*what(void) const noexcept;
		};
		class FormNotSignedException: public std::exception {
			const char	*what(void) const noexcept;
		};
};

std::ostream	&operator<<(std::ostream &stream, const AForm &fm);

#endif
