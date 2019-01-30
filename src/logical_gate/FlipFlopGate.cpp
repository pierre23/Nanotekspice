//
// EPITECH PROJECT, 2018
//
// File description:
//
//

#include <iostream>
#include <string>
#include "logicalGate.hpp"

std::vector<nts::Tristate>      Gate::FlipFlopGate(std::vector<nts::Tristate> &value)
{
	switch ((int)value[_input[2] - 1] + (int)value[_input[3] - 1]) {
		case 0:
			if (value[_input[0] - 1] == nts::TRUE) {
				if (value[_input[1] - 1] == nts::TRUE) {
					value[_output[0] - 1] = nts::TRUE;
					value[_output[1] - 1] = nts::FALSE;
				} else {
					value[_output[0] - 1] = nts::FALSE;
					value[_output[1] - 1] = nts::TRUE;
				}
			}
			return value;
		case 1:
			if (value[_input[2]] == nts::TRUE) {
				value[_output[0] - 1] = nts::FALSE;
				value[_output[1] - 1] = nts::TRUE;
			} else {
				value[_output[0] - 1] = nts::TRUE;
				value[_output[1] - 1] = nts::FALSE;
			}
			return value;
		case 2:
			value[_output[0] - 1] = nts::TRUE;
			value[_output[1] - 1] = nts::TRUE;
			return value;
		default:
			return value;
	}
}
