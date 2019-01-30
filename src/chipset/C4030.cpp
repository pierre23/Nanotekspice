/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "C4030.hpp"
#include "logicalGate.hpp"

C4030::C4030(std::string alias) : AChipset(alias, 14, "4030")
{
	_forbidden.push_back(7);
	_forbidden.push_back(14);
	_gates.push_back(Gate({1, 2}, {3}, &Gate::XorGate));
	_gates.push_back(Gate({5, 6}, {4}, &Gate::XorGate));
	_gates.push_back(Gate({8, 9}, {10}, &Gate::XorGate));
	_gates.push_back(Gate({12, 13}, {11}, &Gate::XorGate));
}
