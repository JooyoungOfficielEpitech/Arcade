/*
** EPITECH PROJECT, 2019
** testgame
** File description:
** joo
*/

#include "../inc/menuGame.hpp"
#include "../inc/pacmanGame.hpp"
#include "../inc/loadLib.hpp"

menu::menu()
{
    loadLib *lib = new loadLib("./lib/lib_arcade_sdl.so");
    Sprite *man = new Sprite(685, 470, "assets/bmp/greenGhost.bmp");
    Sprite *libCursor = new Sprite(357, 525, "assets/bmp/deadGhost.bmp");
    Sprite *button = new Sprite(700, 500, "assets/bmp/button.bmp");

    _stat = MENU;
    _x_cursor_sfml = 357;
    _y_cursor_sfml = 525;
    _x_cursor_sdl = 342;
    _y_cursor_sdl = 665;
    _x_cursor_caca = 357;
    _y_cursor_caca = 800;
    _x_packman = 700;
    _y_packman = 500;
    _x_snake = 700;
    _y_snake = 700;
    _name = "DEFAULT";
    _lib = lib;
    _loop = true;
    _man = man;
    _libCursor = libCursor;
    _button = button;
}

menu::~menu()
{
}

void menu::startGame()
{
    _lib->targetLib->windowCreate("Arcade -- SDL graphics", "assets/font.ttf");
    while (_loop) {
        if (_stat == MENU) {
            handleEvent();
            _lib->targetLib->drawSprite(Sprite(0, 0, "assets/bmp/background.bmp"));
            _lib->targetLib->drawText(Text(1650, 400, 100, "100"));
            _lib->targetLib->drawText(Text(1650, 800, 100, "0"));
            _lib->targetLib->drawText(Text(700, 500, 100, "pacman"));
            _lib->targetLib->drawText(Text(700, 700, 100, "snake"));
            _lib->targetLib->drawSprite(*_button);
            _lib->targetLib->drawSprite(*_libCursor);
            _lib->targetLib->refresh();
            _lib->targetLib->clear();
        }
        else if (_stat == PACMAN) {
            _game->startGame();
             exit(0);
        }
    }
    if (_stat == PACMAN)
        std::cout << "exit with packman\n";
    if (_stat == SNAKE)
        std::cout << "exit with snake\n";
}

void menu::gameLoop()
{
}

void menu::uiLoop()
{
}

void menu::mainLoop()
{
}

std::string menu::getName()
{
    return (_name);
}

void menu::handleEvent()
{
    evt = _lib->targetLib->getEvent();
    if (evt == N) {
        _libCursor->x = _x_cursor_sdl;
        _libCursor->y = _y_cursor_sdl;
    }
    if (evt == P) {
        _libCursor->x = _x_cursor_caca;
        _libCursor->y = _y_cursor_caca;
    }
    if (evt == EXIT)
        _loop = false;
    if (evt == UP) {
        _man->y -= 5;
        _button->x = _x_packman;
        _button->y = _y_packman;
    }
    if (evt == DOWN) {
        _man->y += 5;
        _button->x = _x_snake;
        _button->y = _y_snake;
    }
    if (evt == RIGHT)
        _man->x += 5;
    if (evt == LEFT)
        _man->x -= 5;
    if (evt == ENTER && _button->y == _y_packman) {
        Igames *game = new pacman();

        _game = game;
        _stat = PACMAN;
    }
    if (evt == ENTER && _button->y == _y_snake) {
        _stat = SNAKE;
    }
}
