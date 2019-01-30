/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef CHIPSET_HPP_
	#define CHIPSET_HPP_

	#include <map>
	#include "Error.hpp"
	#include "gate.hpp"

	class AChipset : public nts::IComponent
	{
	public:
		AChipset(std::string alias, int nbr_pin, std::string type);
		~AChipset() = default;
		std::vector<nts::Tristate>	*getCompPin();
		nts::Tristate			getPin(std::size_t) const final;
		void				setLink();
		void				setValPin(nts::Tristate value, std::size_t pin) final;
		nts::Tristate			compute(std::size_t pin = 1) final;
		void				setLink(std::size_t pin,
							nts::IComponent &other,
							std::size_t otherPin) final;
		std::vector<Gate>		getGate() const final;
		std::map<std::size_t, std::pair<std::string, std::size_t>> getLink() const final;
		std::map<std::size_t, std::pair<std::string, std::size_t>> &getLinkR() final;
		std::string			getAlias() const;
		bool				isOutput() const final;
		void				dump() const final;
		std::string			getType() const final;
		unsigned int			getCompTime() const final;
		bool				isLinkToSameGate(const std::size_t &pin);
		std::vector<int>		&getCompStatR();
		const std::vector<std::size_t>	getForbiddenPin() const final;
	protected:
		std::vector<int>						_computeStat;
		unsigned int							_compTime;
		std::string							_type;
		std::string							_alias_chipset;
		std::map<std::size_t, std::pair<std::string, std::size_t>>	_links;
		std::vector<nts::Tristate>					_pins;
		bool								_isOutput;
		std::vector<Gate>						_gates;
		std::vector<std::size_t>					_forbidden;
	};

#endif
