/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef C4094_HPP
#define C4094_HPP

#include "chipset.hpp"

	class C4094 : public AChipset
	{
	public:
		C4094();
		virtual ~C4094();
		virtual Gate			gate_create() = 0;
		std::vector<nts::Tristate>	getCompPin() const;
		nts::Tristate			compute(std::size_t pin = 1);
                void				setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
		void				dump() const;
	private:
		std::string			_alias_chipset;
		std::vector<nts::Tristate>	_pins;
		bool				_is_output;
	protected:
		std::vector<Gate>		_gates;
	};

#endif