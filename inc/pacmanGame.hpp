/*
** EPITECH PROJECT, 2019
** pacmangame
** File description:
** created by jooyoung.kim@epitech.eu
*/

#pragma once

#include "Igames.hpp"
#include "IlibsDyn.hpp"
#include "loadLib.hpp"
#include "libSdl.hpp"

typedef enum
{
    GO,
    STOP,
    MAN
} element_t;

typedef enum
{
    GO_UP,
    GO_DOWN,
    GO_LEFT,
    GO_RIGHT,
    NOTHING
} move_t;

class ghost;
class cell;

class pacman : public Igames
{
public:
    pacman(IlibsDyn *lib);
    ~pacman();
    game_t startGame(event_t, std::string id);
    void gameLoop();
    void uiLoop();
    void mainLoop();
    std::string getName();
    void handleEvent(event_t);
    void loadMap(); //
    void moveUp(char sym); // 
    void moveDown(char sym); // 
    void moveLeft(char sym); // 
    void moveRight(char sym); //
    int getAbs(char sym, int oor); //
    int getOor(char sym); //
    void updateMap();
    void updatePosition();
    void setCells();
    void endGame();

    std::vector<std::pair<std::string, Sprite>> getSpriteVector();
    std::vector<std::pair<std::string, Text>> getTextVector();

    void drawSprite(Sprite target);
    void drawText(Text target);

    void removeSprite(std::string, bool);

    std::string *_map;
    bool _game;
private:
    std::string _id;
    int MAX_SPEED;
    void resetSprite();
    void c_tor();
    ghost *_red;
    ghost *_green;
    ghost *_yellow;
    ghost *_pink;
    int _speed;
    move_t _move;
    IlibsDyn *_lib;
    Sprite *_man;
    std::string _name;
    bool _loop;
    event_t evt;
    Sprite *_up;
    Sprite *_down;
    Sprite *_left;
    Sprite *_right;
    int _score;
    std::vector<cell> _cellVector;
    std::vector<std::pair<std::string, Sprite>> _spriteVector;
    std::vector<std::pair<std::string, Text>> _textVector;
};

class ghost
{
public:
    ghost(char sym, std::string path, std::string name);
    ~ghost();
    void move(pacman *game);
    Sprite getHim();
    void updatePosition(pacman *game);
private:
    bool checkMove(pacman *game);
    bool _alive;
    move_t _move;
    Sprite *_him;
    char _sym;
};

class cell
{
public:
    cell(int x, int y, std::string path, std::string name);
    ~cell();
    int taken();
    Sprite getHim();
    bool _alive;
private:
    Sprite *_him;
};

extern "C" Igames* createGame(IlibsDyn *lib);
extern "C" void destroyGame(Igames *p);
