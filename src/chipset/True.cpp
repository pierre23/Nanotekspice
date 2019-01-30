/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "True.hpp"
#include "logicalGate.hpp"

Ctrue::Ctrue(std::string alias) : AChipset(alias, 1, "true")
{
	_gates.push_back(Gate({}, {1}, &Gate::TrueGate));
}
