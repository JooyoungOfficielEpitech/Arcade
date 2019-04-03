/*
** EPITECH PROJECT, 2019
** i
** File description:
** jooyoung
*/

#include "tools.hpp"

Sprite::Sprite(int x, int y, std::string path, std::string name) : x(x), y(y), path(path), name(name)
{
}

Sprite::~Sprite()
{
}

Text::Text(int x, int y, float size, std::string str) : x(x), y(y), str(str), size(size)
{
}

Text::~Text()
{
}

Sound::Sound(float vol, bool loop, std::string path) : vol(vol), loop(loop), ttf_path(path)
{
}

Sound::~Sound()
{
}
