/*
** EPITECH PROJECT, 2019
** pacman
** File description:
** created by jooyoung.kim@epitech.eu
*/

#include "../inc/pacmanGame.hpp"
#include "../inc/loadLib.hpp"
#include "score.hpp"
#include <fstream>
#include <algorithm>

#define X_POS 670
#define Y_POS 480

extern "C" Igames* createGame(IlibsDyn *lib)
{
    return new pacman(lib);
}

extern "C" void destroyGame(Igames * p)
{
    delete p;
}

pacman::pacman(IlibsDyn *lib)
{
    Sprite *man = new Sprite(670, 480, "assets/bmp/pacmanDown.bmp", "Godown");

    MAX_SPEED = 5;
    _name = "pacman";
    _lib = lib;
    _loop = true;
    _man = man;
    _move = NOTHING;
    loadMap();
    _speed = 0;
    _game = true;
    _red = new ghost('3', "assets/bmp/redGhost.bmp", "red");
    _green = new ghost('4', "assets/bmp/greenGhost.bmp", "green");
    _pink = new ghost('5', "assets/bmp/pinkGhost.bmp", "pink");
    _yellow = new ghost('6', "assets/bmp/yellowGhost.bmp", "yello");
    _up = new Sprite(670, 480, "assets/bmp/pacmanUp.bmp", "Goup");
    _down = new Sprite(670, 480, "assets/bmp/pacmanDown.bmp", "Godown");
    _left = new Sprite(670, 480, "assets/bmp/pacmanLeft.bmp", "Goleft");
    _right = new Sprite(670, 480, "assets/bmp/pacmanRight.bmp", "Goright");
    setCells();
    _score = 0;
}

void pacman::c_tor()
{
    Sprite *man = new Sprite(670, 480, "assets/bmp/pacmanDown.bmp", "Godown");

    MAX_SPEED--;
    _name = "pacman";
    _loop = true;
    _man = man;
    _move = NOTHING;
    loadMap();
    _speed = 0;
    _game = true;
    _red = new ghost('3', "assets/bmp/redGhost.bmp", "red");
    _green = new ghost('4', "assets/bmp/greenGhost.bmp", "green");
    _pink = new ghost('5', "assets/bmp/pinkGhost.bmp", "pink");
    _yellow = new ghost('6', "assets/bmp/yellowGhost.bmp", "yello");
    _up = new Sprite(670, 480, "assets/bmp/pacmanUp.bmp", "Goup");
    _down = new Sprite(670, 480, "assets/bmp/pacmanDown.bmp", "Godown");
    _left = new Sprite(670, 480, "assets/bmp/pacmanLeft.bmp", "Goleft");
    _right = new Sprite(670, 480, "assets/bmp/pacmanRight.bmp", "Goright");
    setCells();
}

pacman::~pacman()
{
    delete(_red);
    delete(_man);
    delete(_green);
    delete(_pink);
    delete(_yellow);
}

void pacman::setCells()
{
    for (int y = 0; y != 19; y++) {
        for (int x = 0; x != 19; x++) {
            if (_map[y].c_str()[x] != '1' && _map[y].c_str()[x] != '2') {
                _cellVector.push_back(cell(X_POS + x * 25, Y_POS +
                                           y * 25, "assets/bmp/cell.bmp",
                                           "cell" + std::to_string(x) +
                                           std::to_string(y)));
            }
        }
    }
}

void pacman::updateMap()
{
    _man->x = (X_POS + (getAbs('2', getOor('2')) * 25));
    _man->y = (Y_POS + (getOor('2') * 25));
    _red->updatePosition(this);
    _green->updatePosition(this);
    _pink->updatePosition(this);
    _yellow->updatePosition(this);
}

void pacman::updatePosition()
{
    if (_speed == MAX_SPEED) {
        _speed = 0;
        if (_move == GO_UP)
            moveUp('2');
        if (_move == GO_DOWN)
            moveDown('2');
        if (_move == GO_LEFT)
            moveLeft('2');
        if (_move == GO_RIGHT)
            moveRight('2');
        _red->move(this);
        _green->move(this);
        _yellow->move(this);
        _pink->move(this);
    }
    _speed++;
    for (auto it = _cellVector.begin(); it != _cellVector.end(); it++)
        if (it->_alive == true)
            return;
    resetSprite();
    c_tor();
}

void pacman::resetSprite()
{
    _spriteVector.erase(_spriteVector.begin(), _spriteVector.end());
}

game_t pacman::startGame(event_t event, std::string id)
{
    _id = id;
    updateMap();
    updatePosition();
    _spriteVector.clear();
    _textVector.clear();
    resetSprite();
    if (_game) {
        drawSprite(Sprite(0, 0, "assets/bmp/background.bmp", "background"));
        drawSprite(Sprite(670, 480, "assets/bmp/map.bmp", "map"));
        drawText(Text(1650, 400, 100, ""));
        drawText(Text(1650, 800, 100, std::to_string(_score)));
        for (auto it = _cellVector.begin(); it != _cellVector.end(); it++) {
            if (it->_alive)
                drawSprite(it->getHim());
        }
        drawSprite(_red->getHim());
        drawSprite(_green->getHim());
        drawSprite(_pink->getHim());
        drawSprite(_yellow->getHim());
        drawSprite(*_man);
    }
    else {
        drawSprite(Sprite(0, 0, "assets/bmp/background.bmp", "background"));
        drawText(Text(700, 800, 100, std::to_string(_score)));
        drawText(Text(670, 480, 100, "GAME OVER"));
    }
    handleEvent(event);
    if (_loop == false) {
        _spriteVector.clear();
        return (MENU);
    }
    else {
        return (PACMAN);
    }
}

void pacman::gameLoop()
{
}

void pacman::uiLoop()
{
}

void pacman::mainLoop()
{
}

std::string pacman::getName()
{
    return (_name);
}

void pacman::handleEvent(event_t event)
{
    evt = event;
    if (evt == ENTER) {
        _loop = false;
    }
    if (evt == UP) {
        _move = GO_UP;
        removeSprite("Go", true);
        _man = _up;
    }
    if (evt == DOWN) {
        _move = GO_DOWN;
        removeSprite("Go", true);
        _man = _down;
    }
    if (evt == RIGHT) {
        removeSprite("Go", true);        
        _move = GO_RIGHT;
        _man = _right;
    }
    if (evt == LEFT) {
        removeSprite("Go", true);
        _move = GO_LEFT;
        _man = _left;
    }
}

void pacman::endGame()
{
    _game = false;
    _lib->resetSprite();
    Score score(_id, _score, "score/pacmanScore");

    score.writeScore();
    score.highestScore();
}
int pacman::getAbs(char sym, int oor)
{
    for (int i = 0; i != 19; i++)
        if (_map[oor].c_str()[i] == sym)
            return (i);
    return (18);
}

int pacman::getOor(char sym)
{
    for (int i = 0; i != 19; i++) {
        if (_map[i].find(sym) != std::string::npos) {
            return (i);
        }
    }
    return (18);
}

void pacman::moveUp(char sym)
{
    int oor = getOor(sym);
    int abs = getAbs(sym, oor);

    if (oor == 0)
        return;
    else {
        _map[oor].replace(abs, 1, "0", 1);
        if (_map[oor - 1].c_str()[abs] == '0') {
            _map[oor - 1].replace(abs, 1, &sym, 1);
            if (sym == '2') {
                for (auto it = _cellVector.begin(); it != _cellVector.end(); it++) {
                    if (it->getHim().name == "cell" + std::to_string(abs) + std::to_string(oor - 1)) {
                        removeSprite("cell" + std::to_string(abs) + std::to_string(oor - 1), false);
                        _score += it->taken();
                    }
                }
            }
        }
        else if (_map[oor - 1].c_str()[abs] != '1' && _map[oor - 1].c_str()[abs] != '0' && sym == '2')
            endGame();
        else
            _map[oor].replace(abs, 1, &sym, 1);
    }
}

void pacman::moveDown(char sym)
{
    int oor = getOor(sym);
    int abs = getAbs(sym, oor);
    
    if (oor == 18)
        return;
    else {
        _map[oor].replace(abs, 1, "0", 1);
        if (_map[oor + 1].c_str()[abs] == '0')
            _map[oor + 1].replace(abs, 1, &sym, 1);
        else if (_map[oor + 1].c_str()[abs] != '1' && _map[oor + 1].c_str()[abs] != '0' && sym == '2')
            endGame();
        else
            _map[oor].replace(abs, 1, &sym, 1);
        if (sym == '2') {
            for (auto it = _cellVector.begin(); it != _cellVector.end(); it++) {
                if (it->getHim().name == "cell" + std::to_string(abs) + std::to_string(oor + 1)) {
                    removeSprite("cell" + std::to_string(abs) + std::to_string(oor + 1), false);
                    _score += it->taken();
                }
            }
        }
    }
}

void pacman::moveLeft(char sym)
{
    int oor = getOor(sym);
    int abs = getAbs(sym, oor);

    if (abs == 0)
        return;
    else {
        _map[oor].replace(abs, 1, "0", 1);
        if (_map[oor].c_str()[abs - 1] == '0')
            _map[oor].replace(abs - 1, 1, &sym, 1);
        else if (_map[oor].c_str()[abs - 1] != '1' && _map[oor].c_str()[abs - 1] != '0' && sym == '2')
            endGame();
        else
            _map[oor].replace(abs, 1, &sym, 1);
    }
    if (sym == '2') {
        for (auto it = _cellVector.begin(); it != _cellVector.end(); it++) {
            if (it->getHim().name == "cell" + std::to_string(abs - 1) + std::to_string(oor)) {
                removeSprite("cell" + std::to_string(abs - 1) + std::to_string(oor), false);
                _score += it->taken();
            }
        }
    }
}

void pacman::moveRight(char sym)
{
    int oor = getOor(sym);
    int abs = getAbs(sym, oor);

    if (abs == 18)
        return;
    else {
        _map[oor].replace(abs, 1, "0", 1);
        if (_map[oor].c_str()[abs + 1] == '0')
            _map[oor].replace(abs + 1, 1, &sym, 1);
        else if (_map[oor].c_str()[abs + 1] != '1' && _map[oor].c_str()[abs + 1] != '0' && sym == '2')
            endGame();
        else
            _map[oor].replace(abs, 1, &sym, 1);
    }
    if (sym == '2') {
        for (auto it = _cellVector.begin(); it != _cellVector.end(); it++) {
            if (it->getHim().name == "cell" + std::to_string(abs + 1) + std::to_string(oor)) {
                removeSprite("cell" + std::to_string(abs + 1) + std::to_string(oor), false);
                _score += it->taken();
            }
        }
    }
}

void pacman::loadMap()
{
    int size = 19;
    int idx = 0;
    std::fstream file;
    
    _map = new std::string[size];
    file.open("assets/binaryMap.txt");
    for (std::string line; getline(file, line);)
        _map[idx++] = line;
}

std::vector<std::pair<std::string, Sprite>> pacman::getSpriteVector()
{
    return (_spriteVector);
}

std::vector<std::pair<std::string, Text>> pacman::getTextVector()
{
    return (_textVector);
}

void pacman::drawSprite(Sprite target)
{
    auto it = _spriteVector.begin();

    while (it != _spriteVector.end()) {
        if (it->first == target.name)
            break;
        else
            it++;
    }
    if (it == _spriteVector.end())
        _spriteVector.push_back(std::make_pair(target.name, target));
    else {
        it->second.x = target.x;
        it->second.y = target.y;
    }
}

void pacman::drawText(Text target)
{
    _textVector.push_back(std::make_pair(target.str, target));
}

void pacman::removeSprite(std::string name, bool all)
{
    for (auto it = _spriteVector.begin(); it != _spriteVector.end(); it++) {
        if (all) {
            if (it->first.find(name) != std::string::npos) {
                it = _spriteVector.erase(it);
                break;
            }
        }
        else {
            if (it->first == name) {
                it = _spriteVector.erase(it);
                break;
            }
        }
    }
}
                
//=================================================================================

ghost::ghost(char sym, std::string path, std::string name)
{
    _sym = sym;
    _alive = true;
    _move = GO_UP;
    _him = new Sprite(100, 100, path, name);
}

ghost::~ghost()
{
    delete(_him);
}

bool ghost::checkMove(pacman *game)
{
    int oor = game->getOor(_sym);
    int abs = game->getAbs(_sym, oor);
    bool ret = false;

    if (_move == GO_UP) {
        if (game->_map[oor - 1].c_str()[abs] == '0' &&
            game->_map[oor + 1].c_str()[abs] != '0' &&
            game->_map[oor].c_str()[abs - 1] != '0' &&
            game->_map[oor].c_str()[abs + 1] != '0'
            )
            ret = true;
        else
            ret = false;
    }
    if (_move == GO_DOWN) {
        if (game->_map[oor - 1].c_str()[abs] != '0' &&
            game->_map[oor + 1].c_str()[abs] == '0' &&
            game->_map[oor].c_str()[abs - 1] != '0' &&
            game->_map[oor].c_str()[abs + 1] != '0'
            )
            ret = true;
        else
            ret = false;
    }
    if (_move == GO_LEFT) {
        if (game->_map[oor - 1].c_str()[abs] != '0' &&
            game->_map[oor + 1].c_str()[abs] != '0' &&
            game->_map[oor].c_str()[abs - 1] == '0' &&
            game->_map[oor].c_str()[abs + 1] != '0'
            )
            ret = true;
        else
            ret = false;
    }
    if (_move == GO_RIGHT) {
        if (game->_map[oor - 1].c_str()[abs] != '0' &&
            game->_map[oor + 1].c_str()[abs] != '0' &&
            game->_map[oor].c_str()[abs - 1] != '0' &&
            game->_map[oor].c_str()[abs + 1] == '0'
            )
            ret = true;
        else
            ret = false;
    }
    return ret;
}

void ghost::move(pacman *game)
{
    int oor = game->getOor(_sym);
    int abs = game->getAbs(_sym, oor);
    std::vector<move_t> moveList;

    if (checkMove(game) == false) {
        if (game->_map[oor - 1].c_str()[abs] == '0') {
            moveList.push_back(GO_UP);
        }
        if (game->_map[oor].c_str()[abs + 1] == '0') {
            moveList.push_back(GO_RIGHT);
        }
        if (game->_map[oor + 1].c_str()[abs] == '0') {
            moveList.push_back(GO_DOWN);
        }
        if (game->_map[oor].c_str()[abs - 1] == '0') {
            moveList.push_back(GO_LEFT);
        }
    }
    if (!moveList.empty()) {
        _move = moveList.at(rand() % moveList.size());
    }
    moveList.clear();
    if (_move == GO_UP)
        game->moveUp(_sym);
    if (_move == GO_DOWN)
        game->moveDown(_sym);
    if (_move == GO_LEFT)
        game->moveLeft(_sym);
    if (_move == GO_RIGHT)
        game->moveRight(_sym);
}

Sprite ghost::getHim()
{
    return (*_him);
}

void ghost::updatePosition(pacman *game)
{
    _him->x = (X_POS + (game->getAbs(_sym, game->getOor(_sym)) * 25));
    _him->y = (Y_POS + (game->getOor(_sym) * 25));
}

cell::cell(int x, int y, std::string path, std::string name)
{
    _him = new Sprite (x, y, path, name);
    _alive = true;
}

cell::~cell()
{
}

int cell::taken()
{
    if (_alive == true) {
        _alive = false;
        return (100);
    }
    else
        return (0);
}

Sprite cell::getHim()
{
    return (*_him);
}
