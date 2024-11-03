// ███████╗████████╗     ██████╗ ██╗   ██╗████████╗ ██████╗██╗  ██╗ █████╗ ██████╗
// ██╔════╝╚══██╔══╝     ██╔══██╗██║   ██║╚══██╔══╝██╔════╝██║  ██║██╔══██╗██╔══██╗
// █████╗     ██║        ██████╔╝██║   ██║   ██║   ██║     ███████║███████║██████╔╝
// ██╔══╝     ██║        ██╔═══╝ ██║   ██║   ██║   ██║     ██╔══██║██╔══██║██╔══██╗
// ██║        ██║███████╗██║     ╚██████╔╝   ██║   ╚██████╗██║  ██║██║  ██║██║  ██║
// ╚═╝        ╚═╝╚══════╝╚═╝      ╚═════╝    ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═╝
//
// <<ShrubberyCreationForm.hpp>>

#include <random>
#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
	AForm("Shrubbery Creation Form", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy):
	AForm(copy), _target(copy.getTarget()) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

// get

const std::string	&ShrubberyCreationForm::getTarget(void) const
{
	return this->_target;
}

// misc

void	ShrubberyCreationForm::execute(const Bureaucrat &bc) const
{
	std::random_device	rand;
	std::ofstream		outfile;
	const tree_t		*tree;
	size_t				i;

	if (this->isExecutable(bc)) {
		outfile.open(this->getTarget() + "_shrubbery");
		tree = &treedb[rand() % 5];
		for (i = 0; i < tree->size; i++)
			outfile << tree->tree[i] << "\n";
		outfile.close();
	}
}
