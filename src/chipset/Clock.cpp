/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <iostream>
#include <string>
#include <cstring>
#include "Clock.hpp"
#include "logicalGate.hpp"

Cclock::Cclock(std::string alias) : AChipset(alias.substr(0, alias.find("=")), 1, "clock")
{
	char    *token = std::strtok((char *)alias.c_str(), "=");

        token = std::strtok(NULL, "=");
        if (std::string(token) == "1")
                _pins[0] = nts::TRUE;
        else if (std::string(token) == "0")
                _pins[0] = nts::FALSE;
        else
                throw Error("Bad parameter value for input");
	_gates.push_back(Gate({}, {1}, &Gate::ClockGate));
}
