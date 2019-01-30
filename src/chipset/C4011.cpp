/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "C4011.hpp"
#include "logicalGate.hpp"

C4011::C4011(std::string alias) : AChipset(alias, 14, "4011")
{
	_forbidden.push_back(7);
	_forbidden.push_back(14);
	_gates.push_back(Gate({1, 2}, {3}, &Gate::NandGate));
	_gates.push_back(Gate({5, 6}, {4}, &Gate::NandGate));
	_gates.push_back(Gate({8, 9}, {10}, &Gate::NandGate));
	_gates.push_back(Gate({12, 13}, {11}, &Gate::NandGate));
}
