// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<Bureaucrat.hpp>>

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <cstdint>
# include <ostream>
# include <exception>

# define _GRADE_MAX 150
# define _GRADE_MIN 1

class Bureaucrat
{
	private:

		const std::string	_name;
		uint8_t				_grade;

	public:

		Bureaucrat(void) = delete;
		Bureaucrat(const std::string &name, const uint8_t &grade);
		Bureaucrat(const Bureaucrat &copy);
		Bureaucrat &operator=(const Bureaucrat &copy) = delete;
		~Bureaucrat(void);

		// get

		const std::string	&getName(void) const;
		const uint8_t		&getGrade(void) const;

		// misc

		void	increaseGrade(void);
		void	decreaseGrade(void);

		// exception

		class GradeTooHighException: public std::exception {
			const char	*what(void) const noexcept;
		};
		class GradeTooLowException: public std::exception {
			const char	*what(void) const noexcept;
		};
};

std::ostream	&operator<<(std::ostream &stream, const Bureaucrat &bc);

#endif
