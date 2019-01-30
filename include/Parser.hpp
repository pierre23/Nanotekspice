/*
** EPITECH PROJECT, 2018
** 
** File description:
** 
*/

#ifndef PARSER_HPP_
	#define PARSER_HPP_

	#include <iostream>
	#include <string>
	#include <memory>
	#include <vector>
	#include "chipset.hpp"
	#include "input.hpp"
	#include "output.hpp"
	#include "C4001.hpp"
	#include "C4008.hpp"	
	#include "C4011.hpp"
	#include "C4030.hpp"
	#include "C4013.hpp"
	#include "C4069.hpp"
	#include "C4071.hpp"
	#include "C4081.hpp"
	#include "Clock.hpp"
	#include "True.hpp"
	#include "False.hpp"

	#define PARS_CHIPSET	".chipsets:"
	#define PARS_LINK	".links:"
	#define CHAR_SEP	'.'
	#define COMMENT_CHAR	"#"
	#define SPACE_SEP	' '
	#define SPACE_STR	" "
	#define TAB_SEP		'\t'

	class Parser
	{
	public:
		Parser(char *av[]);
		~Parser() = default;
		void					compute();
		void					printOutput();
		std::map<std::string, std::unique_ptr<nts::IComponent>> &getComp();
	private:
		int					checkAllParameter(char *av[]);
		int					initialParsingFile(char *av[]);
		void					recursForIngate(std::string alias, std::vector<std::size_t> input);
		nts::Tristate			        findFirstInitial(std::string alias, std::size_t);
		int					parsLink(std::string output, std::string input, int line);
		int					parsingFile(std::vector<std::string> param,
								    char *av[], int line);
		std::unique_ptr<nts::IComponent>	createComponent(const std::string &type,
							       const std::string &value);
	private:
		std::map<std::string, std::unique_ptr<nts::IComponent>>		_component;
	};

#endif
