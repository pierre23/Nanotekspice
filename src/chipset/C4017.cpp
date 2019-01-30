/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "C4017.hpp"
#include "logicalGate.hpp"

C4017::C4017(std::string alias) : AChipset(alias, 15, "4017")
{
	_gates.push_back(Gate({13, 14, 15}, {13}, &Gate::JohnsonGate));
}
