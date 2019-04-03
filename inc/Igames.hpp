/*
** EPITECH PROJECT, 2019
** Interface of the games lib
** File description:
** created by jooyoung.kim@epitech.eu
*/

#pragma once
#include <string>
#include "IlibsDyn.hpp"
#include "tools.hpp"

typedef enum {
    MENU,
    PACMAN,
    SNAKE
} game_t;

class Igames
{
public:
    virtual game_t startGame(event_t, std::string id) = 0;
    virtual void gameLoop() = 0;
    virtual void uiLoop() = 0;
    virtual void mainLoop() = 0;
    virtual std::string getName() = 0;
    virtual void handleEvent(event_t) = 0;

    virtual std::vector<std::pair<std::string, Sprite>> getSpriteVector() = 0;
    virtual std::vector<std::pair<std::string, Text>> getTextVector() = 0;

    virtual void drawSprite(Sprite) = 0;
    virtual void drawText(Text) = 0;

    virtual void removeSprite(std::string, bool) = 0;
};

typedef Igames* create_game(IlibsDyn *);
typedef void destroy_game(Igames *);
