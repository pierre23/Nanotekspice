//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <iostream>
#include <string>
#include "logicalGate.hpp"

std::vector<nts::Tristate>   Gate::NorGate(std::vector<nts::Tristate> &value)
{
	switch ((int)(!(value[_input[0] - 1] | value[_input[1] - 1]))) {
	case true : {
		value[_output[0] - 1] = nts::TRUE;
		return value;
	};
	case false : {
		value[_output[0] - 1] =	nts::FALSE;
                return value;
	}
	default : {
                value[_output[0] - 1] = nts::UNDEFINED;
                return value;
	}
	}
}
