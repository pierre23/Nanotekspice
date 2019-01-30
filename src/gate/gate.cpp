//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include "gate.hpp"

Gate::Gate(std::vector<std::size_t> input, std::vector<std::size_t> output,
	   std::vector<nts::Tristate> (Gate::*logicGate)(std::vector<nts::Tristate> &)) :
	_logicGate(logicGate), _input(input), _output(output), _cOut(nts::UNDEFINED), _cIn(_cOut)
{
	
}

void	Gate::setCarry(nts::Tristate &in)
{
	_cIn = std::ref(in);
}

void	Gate::setCarryInToOut(Gate &toIn)
{
	toIn.setCarry(_cOut);
}

void	Gate::setCarryInToOut(nts::Tristate &in)
{
	_cIn = std::ref(in);
}

std::vector<nts::Tristate>	Gate::computeGate(std::vector<nts::Tristate> &comp_val)
{
	return comp_val = (this->*_logicGate)(comp_val);
}

std::vector<std::size_t>	Gate::getOutput() const
{
	return _output;
}

std::vector<std::size_t>	Gate::getInput() const
{
	return _input;
}

bool				Gate::isInInput(std::size_t pin)
{
	if (!_input.empty())
		for (unsigned int i = 0; i < _input.size(); i++) {
			if (_input[i] == pin)
				return true;
		}
	return false;
}

bool				Gate::isInOutput(std::size_t pin)
{
	if (!_output.empty())
		for (unsigned int i = 0; i < _output.size(); i++) {
			if (_output[i] == pin)
				return true;
		}
	return false;
}
