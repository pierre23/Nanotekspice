/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include "logicalGate.hpp"

std::vector<nts::Tristate>	Gate::AddGate(std::vector<nts::Tristate> &value)
{
	if (value[_input[0] - 1]  == nts::UNDEFINED
		|| (int)value[_input[1] - 1] == nts::UNDEFINED)
		value[_output[0] - 1] = nts::UNDEFINED;
	switch ((int)(value[_input[0] - 1]) + (int)(value[_input[1] - 1])) {
		case 0:
			value[14 - 1] = nts::FALSE;
			if ((((int)_output[0] == 10) ?
				(int)(value[9 - 1])
				: (int)_cIn) == 1)
				value[_output[0] - 1] = nts::TRUE;
			value[_output[0] - 1] = nts::FALSE;
			break;
		case 1:
			if ((((int)_output[0] == 10) ?
				(int)(value[9 - 1])
				: (int)_cIn) == 1) {
				_cOut = nts::TRUE;
				value[14 - 1] = nts::TRUE;
				value[_output[0] - 1] = nts::FALSE;
			}
			_cOut = nts::FALSE;
			value[14 - 1] = nts::FALSE;
			value[_output[0] - 1] = nts::TRUE;
			break;
		case 2:
			if ((((int)_output[0] == 10) ?
				(int)(value[9 - 1])
				: (int)_cIn) == 1) {
				_cOut = nts::TRUE;
				value[14 - 1] = nts::TRUE;
				value[_output[0] - 1] = nts::TRUE;
			}
			_cOut = nts::TRUE;
			value[14 - 1] = nts::TRUE;
			value[_output[0] - 1] = nts::FALSE;
			break;
		default:
			value[_output[0] - 1] = nts::UNDEFINED;
			break;
	}
	return value;
}
