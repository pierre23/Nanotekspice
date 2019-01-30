/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "C4514.hpp"
#include "logicalGate.hpp"

C4514::C4514(std::string alias) : AChipset(alias, 24, false)
{
	_forbidden.push_back(12);
	_forbidden.push_back(24);
	_gates.push_back(Gate({1, 2}, {3}, &Gate::NorGate));
	_gates.push_back(Gate({5, 6}, {4}, &Gate::NorGate));
	_gates.push_back(Gate({8, 9}, {10}, &Gate::NorGate));
	_gates.push_back(Gate({12, 13}, {11}, &Gate::NorGate));
}
