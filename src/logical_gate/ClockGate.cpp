//
// EPITECH PROJECT, 2018
// $
// File description:
// 
//

#include <iostream>
#include <string>
#include "logicalGate.hpp"

std::vector<nts::Tristate>   Gate::ClockGate(std::vector<nts::Tristate> &value)
{
	if (value[0] == nts::TRUE)
		value[_output[0] -1] = nts::FALSE;
	else if (value[0] == nts::FALSE)
		value[_output[0] -1] = nts::TRUE;
	else
		value[_output[0] -1] = nts::UNDEFINED;
	return value;
}
