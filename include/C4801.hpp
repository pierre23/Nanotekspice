/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef C4801_HPP
#define C4801_HPP

#include "chipset.hpp"

	class C4801 : public AChipset
	{
	public:
		C4801();
		virtual ~C4801();
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