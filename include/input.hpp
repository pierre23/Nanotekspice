/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef INPUT_HPP
#define INPUT_HPP

	#include "chipset.hpp"

	class Cinput : public AChipset
	{
	public:
		Cinput(std::string alias);
		~Cinput() = default;
	};

#endif
