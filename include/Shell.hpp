/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef SHELL_HPP_
	#define SHELL_HPP_

	#include <iostream>
	#include <string>
	#include "Parser.hpp"

	class Shell
	{
	public:
		Shell(char *av[]);
		~Shell() = default;
		int		initShell();
	private:
		int		loop(std::string nUse);
		int		display(std::string);
		int		simulate(std::string);
		int		dump(std::string);
		int		setInput(std::string);
		std::map<std::string, int (Shell::*)(std::string)>	_executeFunction;
		Parser							_circuit;
	};

#endif
