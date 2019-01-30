/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "C4013.hpp"
#include "logicalGate.hpp"

C4013::C4013(std::string alias) : AChipset(alias, 14, "4013")
{
	_forbidden.push_back(7);
	_forbidden.push_back(14);
	_gates.push_back(Gate({3, 4, 5, 6}, {1, 2}, &Gate::FlipFlopGate));
	_gates.push_back(Gate({11, 10, 9, 8}, {12, 13}, &Gate::FlipFlopGate));
}
