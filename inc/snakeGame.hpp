/*
** EPITECH PROJECT, 2019
** snakegame
** File description:
** created by jooyoung.kim@epitech.eu
*/

#pragma once

#include "Igames.hpp"
#include "IlibsDyn.hpp"
#include "loadLib.hpp"
#include "libSdl.hpp"
#include "score.hpp"

class snake : public Igames
{
public:
    snake(IlibsDyn *lib);
    ~snake();
    game_t startGame(event_t, std::string);
    void gameLoop();
    void uiLoop();
    void mainLoop();
    std::string getName();
    void handleEvent(event_t);
    void teleport();
    void fruit();
    void bodyCreate();
    int colision();
    std::vector<std::pair<std::string, Sprite>> getSpriteVector();
    std::vector<std::pair<std::string, Text>> getTextVector();
    void endGame();
    void resetSprite();

    void drawSprite(Sprite target);
    void drawText(Text target);

    void removeSprite(std::string name, bool all);

private:
    std::string _id;
    IlibsDyn *_lib;
    Sprite *_fruit;
    std::string _name;
    bool _loop;
    event_t evt;
    int _key;
    int _previouskey;
    int _offset;
    int _score;
    int _size;
    bool _game;
    Sprite *bodyHorz;
    Sprite *bodyVert;
    std::string bodyh;
    std::string bodyv;
    std::vector<std::pair<Sprite, int>> _snakebody;
    std::vector<std::pair<std::string, Sprite>> _spriteVector;
    std::vector<std::pair<std::string, Text>> _textVector;
};

extern "C" Igames* createGame(IlibsDyn *lib);
extern "C" void destroyGame(Igames *p);
