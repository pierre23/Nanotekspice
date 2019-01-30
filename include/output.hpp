/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef OUTPUT_HPP
#define OUTPUT_HPP

	#include "chipset.hpp"

	class Coutput : public AChipset
	{
	public:
		Coutput(std::string alias);
		~Coutput() = default;
	};

#endif
