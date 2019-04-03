/*
** EPITECH PROJECT, 2019
** loadgame
** File description:
** jooyoung
*/

#pragma once

#include "IlibsDyn.hpp"
#include "loadLib.hpp"
#include "Igames.hpp"
#include <iostream>
#include <dlfcn.h>
#include <string>

class loadGame
{
public:
    loadGame(std::string libPath, IlibsDyn *lib);
    ~loadGame();
    IlibsDyn *targetLib;
    Igames *targetGame;
private:
    void *game;
};
