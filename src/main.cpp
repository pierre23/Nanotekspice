//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <string>
#include "Shell.hpp"

int	main(__attribute__((unused))int ac, char *av[])
{
//	try {
		Shell	shell(av);

		shell.initShell();
//	} catch (__attribute__((unused))const Error error){
//		return 84;
//	}
	return 0;
}
