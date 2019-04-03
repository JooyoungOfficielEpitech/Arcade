/*
** EPITECH PROJECT, 2019
** menu.cpp
** File description:
** jooyoung
*/

#include "../inc/menu.hpp"
#include "../inc/score.hpp"

menu::menu(std::string libPath)
{
    loadLib *lib = new loadLib(libPath);
    Sprite *libCursor = new Sprite(357, 525, "assets/bmp/deadGhost.bmp", "deadghost");
    Sprite *button = new Sprite(700, 500, "assets/bmp/button.bmp", "button");

    _id = "";
    _name = libPath.substr(15, libPath.find(".so"));
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
    _lib = lib;
    _loop = true;
    _libCursor = libCursor;
    _button = button;
    _libs = new readDir("lib/", "lib_arcade_");
    _games = new readDir("games/", "lib_arcade_");
    _at_libs = 0;
    _at_games = 0;
}

menu::~menu()
{
}

void menu::updateScore()
{
    Score pacman("", 0, "score/pacmanScore");
    Score nibler("", 0, "score/nibblerScore");

    pacman.highestScore();
    nibler.highestScore();
    _scorePacman = pacman._highestscore;
    _scoreNibler = nibler._highestscore;
}

void menu::mainLoop()
{
    int x_libs = X_LIBS;
    int y_libs = Y_LIBS;
    int x_games;
    int y_games;

    _lib->targetLib->windowCreate("Arcade --Lib " + _name + " graphics", "assets/ARCADE.TTF");
    while (_loop) {
        updateScore();
        x_libs = X_LIBS;
        y_libs = Y_LIBS;
        x_games = X_GAMES;
        y_games = Y_GAMES;
        if (_stat == MENU) {
            _lib->targetLib->drawSprite(Sprite(0, 0, "assets/bmp/background.bmp", "background"));
            _lib->targetLib->drawText(Text(1500, 400, 100, _scorePacman));
            _lib->targetLib->drawText(Text(1400, 800, 100, _scoreNibler));
            for (auto it = _games->fileList.begin(); it != _games->fileList.end(); it++) {
                _lib->targetLib->drawText(Text(x_games, y_games, 100, *it));
                y_games += ADD_GAMES;
            }
        }
        else {
            _stat = _game->targetGame->startGame(_lib->targetLib->getEvent(), _id);
            _lib->targetLib->takeSprite(_game->targetGame->getSpriteVector());
            _lib->targetLib->takeText(_game->targetGame->getTextVector());
        }
        handleEvent();
        for (auto it = _libs->fileList.begin() ; it != _libs->fileList.end(); it++) {
            _lib->targetLib->drawText(Text(x_libs, y_libs, 100, *it));
            y_libs += ADD_LIBS;
        }
        _lib->targetLib->drawText(Text(0, 0, 30, "name: " + _id));
        _lib->targetLib->refresh();
        _lib->targetLib->clear();
        _libs->update();
        _games->update();
        _lib->targetLib->resetText();
    }
}

void menu::changeLibGraph(std::string path)
{
    loadLib *lib = new loadLib(path);

    _lib->targetLib->windowDestroy();
    _lib = lib;
    _lib->targetLib->windowCreate("Arcade -- " + path + " graphics", "assets/ARCADE.TTF");
}

void menu::changeLibGame(std::string path)
{
    loadGame *game = new loadGame(path, _lib->targetLib);

    _game = game;
}

void menu::handleEvent()
{
    evt = _lib->targetLib->getEvent();
    if (evt == SPACE)
        _game = new loadGame(_games->filePath.at(_at_games), _lib->targetLib);
    if (evt == F1) {
        if (_at_libs != _libs->filePath.size() - 1) {
            _at_libs++;
            changeLibGraph(_libs->filePath.at(_at_libs));
        }
    }
    if (evt == F2) {
        _lib->targetLib->resetSprite();
        if (_at_libs != 0) {
            _at_libs--;
            changeLibGraph(_libs->filePath.at(_at_libs));
        }
    }
    if (evt == F3) {
        _lib->targetLib->resetSprite();
        if (_at_games != _games->filePath.size() - 1) {
            _at_games++;
            changeLibGame(_games->filePath.at(_at_games));
            _stat = PACMAN;
        }
    }
    if (evt == F4) {
        if (_at_games != 0) {
            _at_games--;
            changeLibGame(_games->filePath.at(_at_games));
            _stat = PACMAN;
        }
    }
    if (evt == EXIT)
        _loop = false;
    if (evt == BACK)
        _id = _id.substr(0, _id.length() - 1);
    if (evt == A)
        _id = _id + "a";
    if (evt == B)
        _id = _id + "b";
    if (evt == C)
        _id = _id + "c";
    if (evt == D)
        _id = _id + "d";
    if (evt == E)
        _id = _id + "e";
    if (evt == F)
        _id = _id + "f";
    if (evt == G)
        _id = _id + "g";
    if (evt == H)
        _id = _id + "h";
    if (evt == I)
        _id = _id + "i";
    if (evt == J)
        _id = _id + "j";
    if (evt == K)
        _id = _id + "k";
    if (evt == L)
        _id = _id + "l";
    if (evt == M)
        _id = _id + "m";
    if (evt == N)
        _id = _id + "n";
    if (evt == O)
        _id = _id + "o";
    if (evt == P)
        _id = _id + "p";
    if (evt == Q)
        _id = _id + "q";
    if (evt == R)
        _id = _id + "r";
    if (evt == S)
        _id = _id + "s";
    if (evt == T)
        _id = _id + "t";
    if (evt == U)
        _id = _id + "u";
    if (evt == V)
        _id = _id + "v";
    if (evt == W)
        _id = _id + "w";
    if (evt == X)
        _id = _id + "x";
    if (evt == Y)
        _id = _id + "y";
    if (evt == Z)
        _id = _id + "z";
}
