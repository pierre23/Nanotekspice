//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <iostream>
#include "Error.hpp"

Error::Error(const std::string &message) : _message(message)
{
}

const std::string      Error::getCom() const
{
        return _message;
}
