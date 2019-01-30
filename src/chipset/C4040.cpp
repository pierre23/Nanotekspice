/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "C4040.hpp"
#include "logicalGate.hpp"

C4040::C4040(std::string alias) : AChipset(alias, 16, "4040")
{
	_forbidden.push_back(8);
	_forbidden.push_back(16);
	_gates.push_back(Gate({10, 11}, {9}, &Gate::CounterGate));
}
