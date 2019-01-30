/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef LOGICALGATE_HPP_
	#define LOGICALGATE_HPP_

	#include "gate.hpp"

	nts::Tristate   AddGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   AndGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   NandGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   NorGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   NxorGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   OrGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   XorGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   NotGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   ClockGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   TrueGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   FalseGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate	FlipFlopGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   JohnsonGate(std::vector<nts::Tristate> &, std::vector<size_t>);
	nts::Tristate   CounterGate(std::vector<nts::Tristate> &, std::vector<size_t>);

#endif
