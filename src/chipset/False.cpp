/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "False.hpp"
#include "logicalGate.hpp"

Cfalse::Cfalse(std::string alias) : AChipset(alias, 1, "false")
{
	_gates.push_back(Gate({}, {1}, &Gate::FalseGate));
}
