/*
** EPITECH PROJECT, 2019
** testing the game
** File description:
** created by jooyoung.kim
*/

#pragma once

#include "Igames.hpp"
#include "IlibsDyn.hpp"
#include "loadLib.hpp"
#include "libSdl.hpp"

class menu : public Igames
{
public:
    menu();
    ~menu();
    void startGame();
    void gameLoop();
    void uiLoop();
    void mainLoop();
    std::string getName();
    void handleEvent();
private:
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
    Sound *_music;
    bool _loop;
    std::string _name;
    loadLib *_lib;
    event_t evt;
    Igames *_game;
};
