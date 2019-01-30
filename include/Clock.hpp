/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef CLOCK_HPP
#define CLOCK_HPP

	#include "chipset.hpp"

	class Cclock : public AChipset
	{
	public:
		Cclock(std::string alias);
		~Cclock() = default;
	};

#endif
