//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <csignal>
#include "Shell.hpp"

bool	sigintSign = false;

nts::Tristate	intToTristate(int val)
{
	switch (val) {
	case 1 : return nts::TRUE;
        case 0 : return nts::FALSE;
        default : return nts::UNDEFINED;
	}
}

Shell::Shell(char *av[]) : _circuit(av)
{
	_executeFunction["display"] = &Shell::display;
	_executeFunction["simulate"] = &Shell::simulate;
	_executeFunction["="] = &Shell::setInput;
	_executeFunction["dump"] = &Shell::dump;
	_executeFunction["loop"] = &Shell::loop;
}

int	Shell::dump(__attribute__((unused))std::string nUse)
{
	for (auto it = _circuit.getComp().begin(); it != _circuit.getComp().end(); it++) {
		it->second->dump();
	}
	return 0;
}

int	Shell::display(__attribute__((unused))std::string nUse)
{
	_circuit.printOutput();
	return 0;
}

int	Shell::simulate(__attribute__((unused))std::string nUse)
{
        _circuit.compute();
        return 0;
}

int	Shell::setInput(std::string value)
{
	if (_circuit.getComp().count(value.substr(0, value.find("="))) <= 0
	    || (_circuit.getComp()[value.substr(0, value.find("="))]->getType() != "input"
		&& _circuit.getComp()[value.substr(0, value.find("="))]->getType() != "clock")) {
		std::cerr << value.substr(0, value.find("=")) << " is not an input or a clock" << std::endl;
		return 1;
	}
	if (value.substr(value.find("=") + 1, value.length() -1) != "1"
	    && value.substr(value.find("=") + 1, value.length() -1) != "0") {
		std::cerr << "the value \"" << value.substr(value.find("=") + 1, value.length() -1)
			  << "\" is not valid" << std::endl;
		return 1;
	}	
	_circuit.getComp()[value.substr(0, value.find("="))]->setValPin
		(intToTristate
		 (std::stoi(value.substr
			    (value.find("=") + 1, value.length() - 1))), 1);
	return 0;
}

int	Shell::loop(__attribute__((unused))std::string nUse)
{
	while (sigintSign == false)
		this->simulate("0");
	sigintSign = false;
	return 0;
}

int	Shell::initShell()
{
	std::string	command;

	std::signal(SIGINT, [](__attribute__((unused))int param){sigintSign = true;});
	while (command != "exit" && std::cin.good() != 0 && !std::cin.eof()) {
		if (sigintSign == true)
			sigintSign = false;
		std::cout << "> ";
		std::getline(std::cin, command);
		std::string tmp = command;
		if (_executeFunction.count(command) > 0
		    || ((command.find("=") != std::string::npos) ? (command = "=", 1) : (0))) {
			(this->*_executeFunction[command])(((command == "=") ? (tmp) : (command)));
		}
		else if (command != "exit" && command != "")
			std::cerr << command << ": command not found." << std::endl;
		if (sigintSign == true)
			sigintSign = false;
	}
	return 0;
}
