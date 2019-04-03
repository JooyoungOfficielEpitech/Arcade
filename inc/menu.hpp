/*
** EPITECH PROJECT, 2019
** main menu
** File description:
** joo
*/

#pragma once

#include <iterator>

#include "Igames.hpp"
#include "IlibsDyn.hpp"
#include "loadLib.hpp"
#include "loadGame.hpp"
#include "libSdl.hpp"
#include "readDir.hpp"

#define X_GAMES 700
#define Y_GAMES 500
#define ADD_GAMES 100

#define X_LIBS 50
#define Y_LIBS 400
#define ADD_LIBS 100

class menu
{
public:
    menu(std::string libPath);
    ~menu();
    void mainLoop();
    void changeLibGraph(std::string path);
    void changeLibGame(std::string path);
    void handleEvent();
private:
    void updateScore();
    std::string _scorePacman;
    std::string _scoreNibler;
    std::string _id;
    int _at_libs;
    int _at_games;
    std::string _name;
    game_t _stat;
    int _x_cursor_sfml;
    int _y_cursor_sfml;
    int _x_cursor_sdl;
    int _y_cursor_sdl;
    int _x_cursor_caca;
    int _y_cursor_caca;
    int _x_packman;
    int _y_packman;
    int _x_snake;
    int _y_snake;
    Sprite *_libCursor;
    Sprite *_man;
    Sprite *_button;
    bool _loop;
    event_t evt;
    loadLib *_lib;
    loadGame *_game;
    readDir *_games;
    readDir *_libs;
};
