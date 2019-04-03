//
// EPITECH PROJECT, 2019
// SfmlGame.cpp
// File description:
// SfmlGame
//

#include "libSfml.hpp"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

sfmlSprite::sfmlSprite(int x, int y, std::string path, sf::Texture texture, std::string name) : _x(x), _y(y), _path(path), _texture(texture), _name(name)
{
}

sfmlSprite::~sfmlSprite()
{
}

sfmlText::sfmlText(int x, int y, float size, std::string str, sf::Font font) : _x(x), _y(y), _size(size), _str(str), _font(font)
{
}

sfmlText::~sfmlText()
{
}

sfmlSound::sfmlSound(float vol, bool loop, std::string path) : _vol(vol), _loop(loop), _ttf_path(path)
{
}

sfmlSound::~sfmlSound()
{
}

libSfml::libSfml()
{
}

libSfml::~libSfml()
{
}

void libSfml::windowCreate(std::string winName, std::string font)
{
    _font = font;
    _window.create(sf::VideoMode(1920, 1080), winName);
    _window.setFramerateLimit(30);
}

void libSfml::drawSprite(const Sprite target)
{
    sf::Sprite sprite;
    sf::Texture texture;

    auto curr = _spritetexture.begin();
    while (curr != _spritetexture.end()) {
        if (curr->first._name == target.name)
            break;
        curr++;
    }
    if (curr != _spritetexture.end()) {
        curr->first._x = target.x;
        curr->first._y = target.y;
    } else {
        if (!texture.loadFromFile(target.path.c_str()))
            exit (EXIT_FAILURE);
        sprite.setTexture(texture);
        sprite.setPosition(target.x, target.y);
        _spritetexture.push_back(std::make_pair(sfmlSprite(target.x, target.y, target.path, texture, target.name), sprite));
    }
}

void libSfml::drawNum(const int num)
{
    drawText(Text(0, 0, _size, std::to_string(num)));
}

void libSfml::drawText(const Text target)
{
    sf::Font font;
    sf::Text text;

    auto curr = _textfont.begin();
    while (curr != _textfont.end()) {
        if (curr->first._str == target.str)
            break;
        curr++;
    }
    if (curr != _textfont.end()) {
        curr->first._x = target.x;
        curr->first._y = target.y;
    } else {
        if (!font.loadFromFile(_font.c_str()))
            exit (EXIT_FAILURE);
        _size = target.size;
        text.setString(target.str.c_str());
        text.setFont(font);
        text.setCharacterSize(target.size);
        text.setPosition(target.x, target.y);
        _textfont.push_back(std::make_pair(sfmlText(target.x, target.y, target.size, target.str, font), text));
    }
}

void libSfml::playSound(const Sound target)
{
    (void)target;
}

void libSfml::refresh()
{
    for (auto curr = _spritetexture.begin(); curr != _spritetexture.end(); curr++) {
//        std::cout << curr->second._path << std::endl;
        if (curr->second.getTexture() == nullptr)
            curr->first._texture.loadFromFile(curr->first._path);
        curr->second.setTexture(curr->first._texture);
        curr->second.setPosition(curr->first._x, curr->first._y);
        _window.draw(curr->second);
    }
//    std::cout << "+++++++++++++++\n";
    for (auto curr = _textfont.begin(); curr != _textfont.end(); curr++) {
        if (curr->second.getFont() == nullptr)
            curr->first._font.loadFromFile(curr->first._font_path);
        curr->second.setString(curr->first._str);
        curr->second.setFont(curr->first._font);
        curr->second.setCharacterSize(curr->first._size);
        curr->second.setPosition(curr->first._x, curr->first._y);
        _window.draw(curr->second);
    }
    _window.display();
}

void libSfml::clear()
{
    _window.clear();
}

void libSfml::windowDestroy()
{
    _window.close();
}

event_t libSfml::getEvent()
{
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            return (EXIT);
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::BackSpace)
                return (BACK);
            if (event.key.code == sf::Keyboard::Up)
                return (UP);
            if (event.key.code == sf::Keyboard::Down)
                return (DOWN);
            if (event.key.code == sf::Keyboard::Left)
                return (LEFT);
            if (event.key.code == sf::Keyboard::Right)
                return (RIGHT);
            if (event.key.code == sf::Keyboard::Return)
                return (ENTER);
            if (event.key.code == sf::Keyboard::Space)
                return (SPACE);
            if (event.key.code == sf::Keyboard::Escape)
                return (EXIT);
            if (event.key.code == sf::Keyboard::F1)
                return (F1);
            if (event.key.code == sf::Keyboard::F2)
                return (F2);
            if (event.key.code == sf::Keyboard::F3)
                return (F3);
            if (event.key.code == sf::Keyboard::F4)
                return (F4);
        }
        if (event.type == sf::Event::KeyReleased) {
            if (event.key.code == sf::Keyboard::A)
                return (A);
            if (event.key.code == sf::Keyboard::B)
                return (B);
            if (event.key.code == sf::Keyboard::C)
                return (C);
            if (event.key.code == sf::Keyboard::D)
                return (D);
            if (event.key.code == sf::Keyboard::E)
                return (E);
            if (event.key.code == sf::Keyboard::F)
                return (F);
            if (event.key.code == sf::Keyboard::G)
                return (G);
            if (event.key.code == sf::Keyboard::H)
                return (H);
            if (event.key.code == sf::Keyboard::I)
                return (I);
            if (event.key.code == sf::Keyboard::J)
                return (J);
            if (event.key.code == sf::Keyboard::K)
                return (K);
            if (event.key.code == sf::Keyboard::L)
                return (L);
            if (event.key.code == sf::Keyboard::M)
                return (M);
            if (event.key.code == sf::Keyboard::N)
                return (N);
            if (event.key.code == sf::Keyboard::O)
                return (O);
            if (event.key.code == sf::Keyboard::P)
                return (P);
            if (event.key.code == sf::Keyboard::Q)
                return (Q);
            if (event.key.code == sf::Keyboard::R)
                return (R);
            if (event.key.code == sf::Keyboard::S)
                return (S);
            if (event.key.code == sf::Keyboard::T)
                return (T);
            if (event.key.code == sf::Keyboard::U)
                return (U);
            if (event.key.code == sf::Keyboard::V)
                return (V);
            if (event.key.code == sf::Keyboard::W)
                return (W);
            if (event.key.code == sf::Keyboard::X)
                return (X);
            if (event.key.code == sf::Keyboard::Y)
                return (Y);
            if (event.key.code == sf::Keyboard::Z)
                return (Z);
        }
    }
    return (UNKNOWN);
}

void libSfml::resetSprite()
{
     _spritetexture.erase(_spritetexture.begin(), _spritetexture.end());
}

void libSfml::removeSprite(std::string name, bool all)
{
    for (auto curr = _spritetexture.begin(); curr != _spritetexture.end(); curr++) {
        if (all) {
            if (curr->first._name.find(name) != std::string::npos) {
                curr = _spritetexture.erase(curr);
                break;
            }
        } else {
            if (curr->first._name == name) {
                curr  = _spritetexture.erase(curr);
                break;
            }
        }
    }
}
bool libSfml::checkContainsErase(std::string name, std::vector<std::pair<std::string, Sprite>> target)
{
    auto it = target.begin();

    while (it != target.end()) {
        if (name == it->first) {
//            std::cout << name << " found\n";
            return false;
        }
        it++;
    }
//    std::cout << "In SpriteVector, there is no " << name << "\nRemoving the target Sprite\n";
    removeSprite(name, false);
    return true;
}

void libSfml::takeSprite(std::vector<std::pair<std::string, Sprite>> target)
{
    if (target.empty()) {
        resetSprite();
        return;
    }
    for (auto curr = _spritetexture.begin(); curr != _spritetexture.end();  curr++) {
        if (checkContainsErase(curr->first._name, target))
            curr = _spritetexture.begin();
    }
    for (auto curr = target.begin(); curr != target.end();  curr++) {
        drawSprite(curr->second);
    }
}

void libSfml::takeText(std::vector<std::pair<std::string, Text>> target)
{
    for (auto curr = target.begin(); curr != target.end();  curr++) {
        drawText(curr->second);
    }
}

void libSfml::resetText()
{
    _textfont.erase(_textfont.begin(), _textfont.end());
}

//========================================================================================
// DEFINITION OF THE SFML
//========================================================================================

extern "C" IlibsDyn* createLib()
{
    return new libSfml;
}

extern "C" void destroyLib(IlibsDyn * p)
{
    delete p;
}
