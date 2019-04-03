/*
** EPITECH PROJECT, 2019
** class definition of the lib loarder
** File description:
** created by jooyoung.kim@epitech.eu
*/

#pragma once

#include "IlibsDyn.hpp"
#include <iostream>
#include <dlfcn.h>
#include <string>

class loadLib
{
public:
    std::string goo;
    loadLib(std::string libPath);
    ~loadLib();
    IlibsDyn *targetLib;
private:
    void *lib;
};
