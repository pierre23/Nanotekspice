/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "C4069.hpp"
#include "logicalGate.hpp"

C4069::C4069(std::string alias) : AChipset(alias, 14, "4069")
{
	_forbidden.push_back(7);
	_forbidden.push_back(14);
	_gates.push_back(Gate({1}, {2}, &Gate::NotGate));
	_gates.push_back(Gate({3}, {4}, &Gate::NotGate));
	_gates.push_back(Gate({5}, {6}, &Gate::NotGate));
	_gates.push_back(Gate({9}, {8}, &Gate::NotGate));
	_gates.push_back(Gate({11}, {10}, &Gate::NotGate));
	_gates.push_back(Gate({13}, {12}, &Gate::NotGate));
}
