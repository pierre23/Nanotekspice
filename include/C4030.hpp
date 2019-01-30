/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef C4030_HPP
#define C4030_HPP

	#include "chipset.hpp"

	class C4030 : public AChipset
	{
	public:
		C4030(std::string alias);
		~C4030() = default;
	};

#endif