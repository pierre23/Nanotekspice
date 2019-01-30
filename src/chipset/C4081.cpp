/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "C4081.hpp"
#include "logicalGate.hpp"

C4081::C4081(std::string alias) : AChipset(alias, 14, "4081")
{
	_forbidden.push_back(7);
	_forbidden.push_back(14);
	_gates.push_back(Gate({1, 2}, {3}, &Gate::AndGate));
	_gates.push_back(Gate({5, 6}, {4}, &Gate::AndGate));
	_gates.push_back(Gate({8, 9}, {10}, &Gate::AndGate));
	_gates.push_back(Gate({12, 13}, {11}, &Gate::AndGate));
}
