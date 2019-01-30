/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "C4071.hpp"
#include "logicalGate.hpp"

C4071::C4071(std::string alias) : AChipset(alias, 14, "4071")
{
	_forbidden.push_back(7);
	_forbidden.push_back(14);
	_gates.push_back(Gate({1, 2}, {3}, &Gate::OrGate));
	_gates.push_back(Gate({5, 6}, {4}, &Gate::OrGate));
	_gates.push_back(Gate({8, 9}, {10}, &Gate::OrGate));
	_gates.push_back(Gate({12, 13}, {11}, &Gate::OrGate));
}
