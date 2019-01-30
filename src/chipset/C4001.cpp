/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "C4001.hpp"
#include "logicalGate.hpp"

C4001::C4001(std::string alias) : AChipset(alias, 14, "4001")
{
	_forbidden.push_back(7);
	_forbidden.push_back(14);
	_gates.push_back(Gate({1, 2}, {3}, &Gate::NorGate));
	_gates.push_back(Gate({5, 6}, {4}, &Gate::NorGate));
	_gates.push_back(Gate({8, 9}, {10}, &Gate::NorGate));
	_gates.push_back(Gate({12, 13}, {11}, &Gate::NorGate));
}
