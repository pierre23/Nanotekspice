/*
** EPITECH_PROJECT, 2017
** IComponent.cpp
**
** File description:
**
*/

#ifndef ICOMPONENT
	#define ICOMPONENT_HPP

	#include <map>
class Gate;

namespace nts
{
	enum Tristate {
	UNDEFINED = ( - true ) ,
	TRUE = true ,
	FALSE = false
	};

	class IComponent
	{
	public :
		virtual ~ IComponent() = default ;
	public :
		virtual nts::Tristate			compute(std::size_t pin = 1) = 0;
		virtual void				setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin ) = 0;
		virtual void				dump() const = 0;
		virtual std::vector<nts::Tristate>	*getCompPin() = 0;
		virtual std::map<std::size_t, std::pair<std::string, std::size_t>> getLink() const = 0;
		virtual std::map<std::size_t, std::pair<std::string, std::size_t>> &getLinkR() = 0;
		virtual bool				isOutput() const = 0;
		virtual std::vector<Gate>		getGate() const = 0;
		virtual std::string			getAlias() const = 0;
		virtual void				setValPin(nts::Tristate value, std::size_t pin) = 0;
		virtual nts::Tristate			getPin(std::size_t) const = 0;
		virtual std::string			getType()const = 0;
		virtual unsigned int			getCompTime() const = 0;
		virtual std::vector<int>		&getCompStatR() = 0;
		virtual const std::vector<std::size_t>	getForbiddenPin() const = 0;
	};
}

#endif
