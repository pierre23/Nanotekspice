/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef GATE_HPP_
	#define GATE_HPP_

	#include <iostream>
	#include <vector>
	#include <functional>
	#include <memory>
	#include "IComponent.hpp"

	class Gate
	{
	public:
		Gate(std::vector<std::size_t> input, std::vector<std::size_t> output,
		     std::vector<nts::Tristate> (Gate::*)(std::vector<nts::Tristate> &));
		~Gate() = default;
		void				setCarry(nts::Tristate &);
		void				setCarryInToOut(Gate &toIn);
	        void				setCarryInToOut(nts::Tristate &in);
		std::vector<std::size_t>	getOutput() const;
		std::vector<std::size_t>	getInput() const;
		std::vector<nts::Tristate>	computeGate(std::vector<nts::Tristate> &);
		bool				isInInput(std::size_t pin);
		bool				isInOutput(std::size_t pin);
		std::vector<nts::Tristate>	NorGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>      AddGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>	AndGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>	ClockGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>	FalseGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>      FlipFlopGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>	NandGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>	NxorGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>	OrGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>	NotGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>	TrueGate(std::vector<nts::Tristate> &value);
		std::vector<nts::Tristate>	XorGate(std::vector<nts::Tristate> &value);
	private:
		std::vector<nts::Tristate> (Gate::*_logicGate)(std::vector<nts::Tristate> &);
		std::vector<size_t>		_input;
		std::vector<size_t>		_output;
		nts::Tristate			_cOut;
		nts::Tristate			&_cIn;
	};

#endif
