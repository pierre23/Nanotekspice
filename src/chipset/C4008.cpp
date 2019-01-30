/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include <memory>
#include "C4008.hpp"
#include "logicalGate.hpp"

C4008::C4008(std::string alias) : AChipset(alias, 16, "4008")
{
	_forbidden.push_back(8);
	_forbidden.push_back(16);
	_gates.push_back(Gate({15, 1}, {13}, &Gate::AddGate));
	_gates.push_back(Gate({2, 3}, {12}, &Gate::AddGate));
	_gates.push_back(Gate({4, 5}, {11}, &Gate::AddGate));
	_gates.push_back(Gate({6, 7, 9}, {10}, &Gate::AddGate));
	_gates[3].setCarryInToOut(_pins[9 - 1]);
	_gates[2].setCarryInToOut(_gates[3]);
	_gates[1].setCarryInToOut(_gates[2]);
	_gates[0].setCarryInToOut(_gates[1]);
}
