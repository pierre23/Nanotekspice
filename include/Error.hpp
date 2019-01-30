/*
** EPITECH PROJECT, 2018
**
** File description:
**
*/

#ifndef ERROR_HPP_
	#define ERROR_HPP_

#include <string>

	class Error : public std::exception
	{
	public:
		Error() = default;
		Error(std::string const &message);
		~Error() = default;
		const std::string      getCom() const;
	private:
		std::string	_message;
		bool		_exitOr;
	};

#endif
