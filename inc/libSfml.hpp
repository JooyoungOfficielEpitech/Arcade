/*
** EPITECH PROJECT, 2019
** lib class for the sfml
** File description:
** created by jooyoung
*/

#pragma once

#include "IlibsDyn.hpp"
#include <SFML/Graphics/Text.hpp>
#include "tools.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <vector>

class sfmlSprite : public Sprite
{
public:
    sfmlSprite(int x, int y, std::string path, sf::Texture texture, std::string name);
    ~sfmlSprite();
    int _x;
    int _y;
    std::string _path;
    sf::Texture _texture;
    std::string _name;
};

class sfmlText : public Text
{
public:
    int _x;
    int _y;
    float _size;
    std::string _str;
    std::string _font_path;
    sf::Font _font;
    sfmlText(int x, int y, float size, std::string str, sf::Font font);
    ~sfmlText();
};

class sfmlSound : public Sound
{
public:
    float _vol;
    bool _loop;
    std::string _ttf_path;
    sfmlSound(float vol, bool loop, std::string path);
    ~sfmlSound();
};

class libSfml : public IlibsDyn
{
public:
    sf::RenderWindow _window;
    sf::Texture _texture;
    sf::Sprite _sprite;
    std::string _font;
    float _size;
    sf::Text _text;
    std::vector<std::pair<sfmlSprite ,sf::Sprite>> _spritetexture;
    std::vector<std::pair<sfmlText, sf::Text>> _textfont;
public:
    libSfml();
    ~libSfml();
    void drawSprite(const Sprite target);
    void drawNum(const int num);
    void drawText(const Text target);
    void playSound(const Sound target);
    void refresh();
    void windowCreate(std::string winName, std::string font);
    void clear();
    void windowDestroy();
    event_t getEvent();
    bool checkContainsErase(std::string name, std::vector<std::pair<std::string, Sprite>> target);
    void takeSprite(std::vector<std::pair<std::string, Sprite>> target);
    void takeText(std::vector<std::pair<std::string, Text>> target);
    void resetSprite();
    void removeSprite(std::string name, bool all);
    void resetText();
};

extern "C" IlibsDyn* createLib();
extern "C" void destroyLib(IlibsDyn* p);
