//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <iostream>
#include <string>
#include "logicalGate.hpp"

std::vector<nts::Tristate>   Gate::TrueGate(std::vector<nts::Tristate> &value)
{
	value[_output[0] - 1] = nts::TRUE;
	return value;
}
