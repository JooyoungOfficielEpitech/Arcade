/*
** EPITECH PROJECT, 2019
** head file of the assets classes
** File description:
** create by jooyoung
*/

#pragma once

#include <string>

//================================================================================
// DEFINITION OF THE SPRITE CLASS
//================================================================================

class Sprite
{
public:
    int x;
    int y;
    std::string path;
    std::string name;
    Sprite(int x = 0, int y = 0, std::string path = "", std::string name = "");
    ~Sprite();
};

//================================================================================
// END DEFINITION OF THE SPRITE CLASS
//================================================================================

//================================================================================
// DEFINITION OF THE TEXT CLASS
//================================================================================

class Text
{
public:
    int x;
    int y;
    float size;
    std::string str;
    std::string font_path;
    Text(int x = 0, int y = 0, float size=100, std::string str= "");
    ~Text();
};

//================================================================================
// END DEFINITION OF THE TEXT CLASS
//================================================================================

//================================================================================
// DEFINITION OF THE SOUND CLASS
//================================================================================

class Sound
{
public:
    float vol;
    bool loop;
    std::string ttf_path;
    Sound(float vol = 10, bool loop = false, std::string path = "");
    ~Sound();
};

//================================================================================
// END DEFINITION OF THE SOUND CLASS
//================================================================================
