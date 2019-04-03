/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** __DES
*/

#include "libcaca.hpp"

libCacaSprite::libCacaSprite(int x, int y, std::string path) : _x(x), _y(y), _path(path)
{

}

libCacaSprite::~libCacaSprite()
{

}

libCacaText::libCacaText(int x, int y, float size, std::string str) : _x(x), _y(y), _size(size), _str(str)
{
}

libCacaText::~libCacaText()
{
}

libCaca::libCaca()
{
}

libCaca::~libCaca()
{
}

void libCaca::drawText(const Text target)
{
    caca_put_str(_can, target.x / 9.94, target.y / 16.8, target.str.c_str());
    caca_refresh_display(_win);
}

void libCaca::drawSprite(const Sprite target)
{
    int size = 100;
    std::fstream file;
    std::string pic;

    file.open(target.path);
    for (std::string line; getline(file, line);) {
        pic += line;
    }
    drawText(Text(target.x, target.y, size, pic));
}

void libCaca::drawNum(const int num)
{
// drawText(Text(0, 0, size, std::to_string(num))); There is no num class :/
}

void libCaca::playSound(const Sound target) //NOPE
{
}

void libCaca::refresh()
{
    caca_refresh_display(_win);
}

void libCaca::windowCreate(std::string winName, std::string font)
{
    _can = caca_create_canvas(193, 64);
    _win = caca_create_display(_can);
    caca_set_display_title(_win, winName.c_str());
}

void libCaca::clear()
{
    caca_free_canvas(_can);
}

void libCaca::windowDestroy()
{
    caca_free_canvas(_can);
    caca_free_display(_win);
}

event_t libCaca::getEvent()
{
    caca_event_t ev;
    caca_key key;

    if (caca_get_event(_win, CACA_EVENT_KEY_RELEASE, &ev, 0) == 1) {
        if (ev.data.key.ch == CACA_KEY_UP)
            return (UP);
        if (ev.data.key.ch == CACA_KEY_DOWN)
            return (DOWN);
        if (ev.data.key.ch == CACA_KEY_LEFT)
            return (LEFT);
        if (ev.data.key.ch == CACA_KEY_RIGHT)
            return (RIGHT);
        if (ev.data.key.ch == CACA_KEY_ESCAPE)
            return (EXIT);
        if (ev.data.key.ch == CACA_KEY_F1)
            return (F1);
        if (ev.data.key.ch == CACA_KEY_F2)
            return (F2);
        if (ev.data.key.ch == CACA_KEY_F3)
            return (F3);
        if (ev.data.key.ch == CACA_KEY_F4)
            return (F4);
        if (ev.data.key.ch == CACA_KEY_RETURN)
            return (ENTER);
        if (ev.data.key.ch == CACA_KEY_BACKSPACE)
            return (BACK);
        if (ev.data.key.ch == ' ')
            return (SPACE);
        if (ev.data.key.ch == 'a')
            return (A);
        if (ev.data.key.ch == 'b')
            return (B);
        if (ev.data.key.ch == 'c')
            return (C);
        if (ev.data.key.ch == 'd')
            return (D);
        if (ev.data.key.ch == 'e')
            return (E);
        if (ev.data.key.ch == 'f')
            return (F);
        if (ev.data.key.ch == 'g')
            return (G);
        if (ev.data.key.ch == 'h')
            return (H);
        if (ev.data.key.ch == 'i')
            return (I);
        if (ev.data.key.ch == 'j')
            return (J);
        if (ev.data.key.ch == 'k')
            return (K);
        if (ev.data.key.ch == 'l')
            return (L);
        if (ev.data.key.ch == 'm')
            return (M);
        if (ev.data.key.ch == 'n')
            return (N);
        if (ev.data.key.ch == 'o')
            return (O);
        if (ev.data.key.ch == 'p')
            return (P);
        if (ev.data.key.ch == 'q')
            return (Q);
        if (ev.data.key.ch == 'r')
            return (R);
        if (ev.data.key.ch == 's')
            return (S);
        if (ev.data.key.ch == 't')
            return (T);
        if (ev.data.key.ch == 'u')
            return (U);
        if (ev.data.key.ch == 'v')
            return (V);
        if (ev.data.key.ch == 'w')
            return (W);
        if (ev.data.key.ch == 'x')
            return (X);
        if (ev.data.key.ch == 'y')
            return (Y);
        if (ev.data.key.ch == 'z')
            return (Z);
        else
            return (UNKNOWN);
        }
}

void libCaca::resetSprite()
{
    _spriteVector.erase(_spriteVector.begin(), _spriteVector.end());
}

void libCaca::resetText()
{
    _textVector.erase(_textVector.begin(), _textVector.end());
}

void libCaca::removeSprite(std::string name, bool all)
{
    for (auto it = _spriteVector.begin(); it != _spriteVector.end(); it++) {
        if (all) {
            if (it->first.find(name) != std::string::npos) {
                _spriteVector.erase(it);
                break;
            }
        }
        else
            if (it->first == name) {
                _spriteVector.erase(it);
                break;
            }
    }
}

void libCaca::takeSprite(std::vector<std::pair<std::string, Sprite>> target)
{
    for (auto curr = target.begin(); curr != target.end();  curr++) {
        drawSprite(curr->second);
    }
}

void libCaca::takeText(std::vector<std::pair<std::string, Text>> target)
{
    for (auto curr = target.begin(); curr != target.end();  curr++) {
        drawText(curr->second);
    }
}


extern "C" IlibsDyn* createLib()
{
    return new libCaca;
}

extern "C" void destroyLib(IlibsDyn * p)
{
    delete p;
}
