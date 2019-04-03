/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** __DES
*/

#include "IlibsDyn.hpp"
#include <caca.h>
#include <fstream>
#include <iostream>
#include <vector>

class libCacaSprite : public Sprite
{
public:
    libCacaSprite(int x, int y, std::string path);
    ~libCacaSprite();
    std::string _path;
    int _x;
    int _y;
};

class libCacaText : public Text
{
public:
    int _x;
    int _y;
    std::string _str;
    std::string _font_path;
    float _size;
    libCacaText(int x, int y, float size, std::string str);
    ~libCacaText();
};

class libCaca : public IlibsDyn
{
public:
    caca_canvas_t *_can;
    caca_display_t *_win;
    std::vector<std::pair<std::string, Sprite>> _spriteVector;
    std::vector<std::pair<std::string, Text>> _textVector;

    libCaca();
    ~libCaca();
    void drawText(const Text target);
    void drawSprite(const Sprite target);
    void drawNum(const int num);
    void playSound(const Sound target);
    void refresh();
    void windowCreate(std::string winName, std::string font);
    void clear();
    void windowDestroy();
    event_t getEvent();
    void resetSprite();
    void removeSprite(std::string name, bool all);

    void takeSprite(std::vector<std::pair<std::string, Sprite>>);
    void takeText(std::vector<std::pair<std::string, Text>>);

    void resetText();
};

extern "C" IlibsDyn* createLib();
extern "C" void destroyLib(IlibsDyn* p);
