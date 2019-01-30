/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#include <fstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <functional>
#include "Parser.hpp"

using lambdaCreate = std::function<std::unique_ptr<nts::IComponent>(std::string)>;
using Cmap = std::map<std::string, lambdaCreate>;

static Cmap creationTabl = {
	// {"2716", [](std::string type){return std::unique_ptr<nts::IComponent>{new C2716(type)};}},
	{"4008", [](std::string type){return std::unique_ptr<nts::IComponent> {new C4008(type)};}},
	{"4013", [](std::string type){return std::unique_ptr<nts::IComponent> {new C4013(type)};}},
	{"4030", [](std::string type){return std::unique_ptr<nts::IComponent> {new C4030(type)};}},
	{"4069", [](std::string type){return std::unique_ptr<nts::IComponent> {new C4069(type)};}},
	{"4081", [](std::string type){return std::unique_ptr<nts::IComponent> {new C4081(type)};}},
	// {"4514", [](std::string type){return std::unique_ptr<nts::IComponent> p(new C4014(type));}},
	{"4001", [](std::string type){return std::unique_ptr<nts::IComponent>{new C4001{type}};}},
	{"4011", [](std::string type){return std::unique_ptr<nts::IComponent> {new C4011(type)};}},
	// {"4017", [](std::string type){return std::unique_ptr<nts::IComponent> p(new C4017(type));}},
	// {"4040", [](std::string type){return std::unique_ptr<nts::IComponent> p(new C4040(type));}},
	{"4071", [](std::string type){return std::unique_ptr<nts::IComponent> {new C4071(type)};}},
	// {"4094", [](std::string type){return std::unique_ptr<nts::IComponent> p(new C4094(type));}},
	// {"4801", [](std::string type){return std::unique_ptr<nts::IComponent> p(new C4801(type));}},
	{"input", [](std::string type){return std::unique_ptr<nts::IComponent>{new Cinput(type)};}},
	{"output", [](std::string type){return std::unique_ptr<nts::IComponent>{new Coutput(type)};}},
	{"clock", [](std::string type){return std::unique_ptr<nts::IComponent> {new Cclock(type)};}},
	{"true", [](std::string type){return std::unique_ptr<nts::IComponent> {new Ctrue(type)};}},
	{"false", [](std::string type){return std::unique_ptr<nts::IComponent> {new Cfalse(type)};}}
};

std::map<std::string, std::unique_ptr<nts::IComponent>> &Parser::getComp()
{
	return _component;
}

void	Parser::printOutput()
{
	std::vector<std::string>	tmp;

	for (auto it = _component.begin(); it != _component.end(); it++)
		if (it->second->isOutput() == true)
			tmp.push_back(it->first);
	for (unsigned int i = 0; i < tmp.size(); i++) {
		std::cout << tmp[i] << "=" << _component[tmp[i]]->getPin(1) << std::endl;
	}
}

void	Parser::recursForIngate(std::string alias,
				std::vector<std::size_t> input)
{
	for (unsigned int i = 0; i < input.size(); i++)
	        this->findFirstInitial(alias, input[i]);
}

nts::Tristate	Parser::findFirstInitial(std::string alias, std::size_t pin)
{
	for (unsigned int i = 0; !_component[alias]->getGate().empty()
		     && i < _component[alias]->getGate().size(); i++) {
		if (_component[alias]->getGate()[i].isInOutput(pin) == true
		    && _component[alias]->getCompStatR()[pin - 1] == 0) {
			recursForIngate(alias, _component[alias]->
					getGate()[i].getInput());
		}
	}
	_component[alias]->getCompStatR()[pin - 1] += 1;
	if (!_component[alias]->getLink().empty() &&
	    _component[alias]->getLink().count(pin) > 0
	    && _component[alias]->getCompStatR()[pin - 1] == 1
		) {
		_component[alias]->setValPin(findFirstInitial
					     (_component[alias]->getLink()[pin].first,
					      _component[alias]->getLink()[pin].second), pin);
	}
	_component[alias]->getCompStatR()[pin -1] = 0;
	return _component[alias]->compute(pin);
}

void		Parser::compute()
{
	for (auto it = _component.begin(); it !=
		     _component.end(); it++) {
		if (it->second->isOutput() == true) {
			if (it->second->getLink().empty())
				throw Error("No link for the output named => "
					    + it->second->getAlias());
			this->findFirstInitial(it->first, 1);
		}
	}
}

std::string	validLine(std::string line, int *i)
{
	*i += 1;
	if (line.find(COMMENT_CHAR) != std::string::npos)
		line = line.substr(0, line.find(COMMENT_CHAR));
	return line;
}

std::unique_ptr<nts::IComponent>        Parser::createComponent
(const std::string &type, const std::string &value)
{
	if (value.find("=") == std::string::npos) {
		if (_component.count(value) > 0)
			throw Error("Component named " + value
				    + " can't be declare many time");
	}
	else
		if (_component.count(value.substr(0, value.find("="))) > 0)
                        throw Error("Component named " + value.substr
				    (0, value.find("="))
				    + " can't be declare many time");
	if (creationTabl.count(type) <= 0)
		throw Error("Unknow Chipset type => " + type);
	return creationTabl[type](value);
}
//------------------------------------------------------------------------------
std::string	findValueParam(char *av[], std::string alias)
{
	for (int i = 0; av[i]; i++) {
		if (std::string(av[i]).find("=") == std::string::npos ||
		    std::string(av[i]).find("=") == std::string(av[i]).length() - 1)
			throw Error(
				"Bad format for parameter input_name=value");
		if (std::string(av[i]).substr
		    (0, std::string(av[i]).find("=")) == alias) {
			return std::string(av[i]);
		}
	}
	throw Error("Expected value as parameter for each input or clock");
	return nullptr;
}

int		Parser::parsLink(std::string output, std::string input, int line)
{
	if (output.find(":") == std::string::npos|| input.find(":") == std::string::npos)
		throw Error("bad link syntax line " + std::to_string(line) + "| chipsetName:pin");
	if (_component.count(output.substr(0, output.find(":"))) <= 0
	    || _component.count(input.substr(0, input.find(":"))) <= 0) {
		throw Error("Bad chipset's name in section .links, line : " + std::to_string(line));
	}
	try {
		if ((output.substr(output.find(":") + 1, output.length() - 1)).
		    find_first_not_of("0123456789") != std::string::npos
		    || (input.substr(input.find(":") + 1, input.length() - 1)).
                    find_first_not_of("0123456789") != std::string::npos)
			throw Error("Not only digit in pin line " + std::to_string(line));
		std::size_t	outputVal = std::stoi
			(output.substr(output.find(":") + 1, output.length() - 1));
		std::size_t	inputVal = std::stoi
			(input.substr(input.find(":") + 1, input.length() - 1));
		if (outputVal > _component[output.substr(0, output.find(":"))]->getCompPin()->size()
		    || inputVal > _component[input.substr(0, input.find(":"))]->getCompPin()->size())
			throw Error("Pin doesn't exist for this chipset line " + std::to_string(line));
		_component[output.substr(0, output.find(":"))]
			->setLink(outputVal, *(_component[input.substr
							  (0, input.find(":"))])
				  , inputVal);
	} catch (const std::exception &error) {
		throw Error("Bad pin value line " + std::to_string(line));
	}
	return 0;
}

int		Parser::parsingFile(std::vector<std::string> param, char *av[], int line)
{
	static int	flag = 0;

	if (!param.empty() && flag == 1 && param.size() == 2) {
		std::string	tmp = param[1];
		if (param[0] == "input" || param[0] == "clock")
			tmp = findValueParam(&av[2], param[1]);
		_component.insert(std::pair<std::string, std::unique_ptr<nts::IComponent>>
				  (param[1], std::move(this->createComponent(param[0], tmp))));
	}
	else if (!param.empty() && flag == 2 && param.size() == 2)
		this->parsLink(param[0], param[1], line);
	else if (!param.empty()) {
		if (param[0] == PARS_CHIPSET)
			flag = 1;
		else if (param[0] == PARS_LINK)
			(flag == 1) ? (flag = 2) : (throw Error("links section before chipset section"));
		else if ((param[0][0] == CHAR_SEP) || param.size() > 2) {
			throw Error("Bad section name => " + param[0] + ", ligne " + std::to_string(line));
		}
	}
	return flag;
}

int	Parser::initialParsingFile(char *av[])
{
	std::ifstream			fd(av[1]);
	std::string			line;
	std::vector<std::string>	param;
	int				i = 0;
	int				ret = 0;
	
	while (fd && getline(fd, line)) {
		line = validLine(line, &i);
		std::replace(line.begin(), line.end(), TAB_SEP, SPACE_SEP);
		char *token = std::strtok((char *)line.c_str(), SPACE_STR);
		while (token != NULL) {
			param.push_back(std::string(token));
			token = std::strtok(NULL, SPACE_STR);
		}
		if (!param.empty() && param.size() != 2 && param[0][0] != '.')
			throw Error("Bad arg number line " + std::to_string(i));
		ret = this->parsingFile(param, av, i);
		param.clear();
	}
	if (ret != 2)
		throw Error("Where are no .links section");
	return 0;
}

int	tablen(char *av[])
{
	int	i = 0;

	while (av[i])
		i++;
	return i;
}

int	Parser::checkAllParameter(char *av[])
{
	for (int i = 0; av[i]; i++) {
		if (_component.count(std::string(av[i]).substr
				     (0, std::string(av[i]).find("="))) <= 0)
		    throw Error("No correspondance for " + std::string(av[i]).substr
				(0, std::string(av[i]).find("=")) +
			    " input, provide as parameter");
	}
	return 0;
}

Parser::Parser(char *av[])
{
	try {
		this->initialParsingFile(av);
		this->checkAllParameter(&av[2]);
		this->compute();
		this->printOutput();	
	} catch (const Error &error) {
		std::cerr << "Error: " << error.getCom() << std::endl;
		throw Error();
	}
}
