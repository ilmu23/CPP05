// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Form.hpp>>

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <cstdint>
# include <ostream>
# include <exception>
# include "Bureaucrat.hpp"

# define _MAX(x, y)	((x > y) ? x : y)
# define _MIN(x, y)	((x < y) ? x : y)

class Form
{
	private:

		const std::string	_name;
		bool				_signed;
		const uint8_t		_s_grade;
		const uint8_t		_e_grade;

	public:

		Form(void) = delete;
		Form(const std::string &name, const uint8_t &s_grade, const uint8_t &e_grade);
		Form(const Form &copy);
		Form &operator=(const Form &copy) = delete;
		~Form(void);

		// get

		const std::string	&getName(void) const;
		const bool			&getSigned(void) const;
		const uint8_t		&getSignGrade(void) const;
		const uint8_t		&GetExecGrade(void) const;

		// misc

		void	beSigned(const Bureaucrat &bc);

		// exception

		class GradeTooHighException: public std::exception {
			const char	*what(void) const noexcept;
		};
		class GradeTooLowException: public std::exception {
			const char	*what(void) const noexcept;
		};
};

std::ostream	&operator<<(std::ostream &stream, const Form &fm);

#endif
