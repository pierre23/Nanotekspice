/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#include <algorithm>
#include "chipset.hpp"

AChipset::AChipset(std::string alias, int nbrPin, std::string type) :  _compTime(-1), _type(type), _alias_chipset(alias)
{
	_computeStat.insert(_computeStat.end(), nbrPin, 0);
	_pins.insert(_pins.end(), nbrPin, nts::UNDEFINED);
}

std::vector<nts::Tristate>   *AChipset::getCompPin()
{
	return &_pins;
}

std::vector<int>			&AChipset::getCompStatR()
{
	return _computeStat;
}

void		AChipset::setValPin(nts::Tristate value, std::size_t pin)
{
	if (value != 0 && value != 1 && value != -1)
		return;
	_pins[pin - 1] = value;
}

nts::Tristate	AChipset::getPin(std::size_t pin) const
{
	return _pins[pin - 1];
}

unsigned int	AChipset::getCompTime() const
{
	return _compTime;
}

nts::Tristate   AChipset::compute(std::size_t pin)
{
	_compTime += 1;
	if (_type == "clock" && _compTime == 0)
		return _pins[pin - 1];
	for (unsigned int i = 0; i < _gates.size(); i++) {
		if (_gates[i].isInOutput(pin) == true) {
			_gates[i].computeGate(_pins);
			return _pins[pin - 1];
		}
	}
	return _pins[pin - 1];
}

std::string		AChipset::getType() const
{
	return _type;
}

bool				AChipset::isOutput() const
{
	if (_type == "output")
		return true;
	return false;
}

std::vector<Gate>               AChipset::getGate() const
{
	return _gates;
}

std::map<std::size_t, std::pair<std::string, std::size_t>> AChipset::getLink() const
{
	return _links;
}
std::map<std::size_t, std::pair<std::string, std::size_t>> &AChipset::getLinkR()
{
	return _links;
}

std::string	AChipset::getAlias() const
{
	return _alias_chipset;
}

const std::vector<std::size_t>  AChipset::getForbiddenPin() const
{
	return _forbidden;
}

void            AChipset::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
	for (unsigned int i = 0; !this->getGate().empty()
		     && i < this->getGate().size(); i++)
		if ((this->getGate()[i].isInInput(pin) && this->getType() != "clock")
		    || other.getType() == "input")
			this->getLinkR()[pin] = std::make_pair(other.getAlias(), otherPin);
		else if (this->getGate()[i].isInOutput(pin) == true || other.isOutput() == true)
			other.getLinkR()[otherPin] = std::make_pair(_alias_chipset, pin);
	for (unsigned int i = 0; !other.getGate().empty()
		     && i < other.getGate().size(); i++)
		if ((other.getGate()[i].isInInput(otherPin) && other.getType() != "clock")
		    || this->getType() == "input")
			other.getLinkR()[otherPin] = std::make_pair(_alias_chipset, pin);
		else if (other.getGate()[i].isInOutput(otherPin) == true || this->isOutput() == true)
			this->getLinkR()[pin] = std::make_pair(other.getAlias(), otherPin);
	if (this->getGate().empty() && other.getGate().empty()) {
		if (this->isOutput())
			this->getLinkR()[pin] = std::make_pair(other.getAlias(), otherPin);
		else
			other.getLinkR()[otherPin] = std::make_pair(_alias_chipset, pin);
	}
}

void                            AChipset::dump() const
{
	std::cout << this->getAlias() << ":\n";
	for (unsigned int i = 0; i < _pins.size(); i++)
		std::cout << i+1 << " : " << _pins[i] << std::endl;
	std::cout << "link :" << std::endl;
	for (auto it = _links.begin(); it != _links.end(); it++) {
		std::cout << it->first << " => " <<
			it->second.first << "-" <<
			it->second.second << std::endl;
	}
}
