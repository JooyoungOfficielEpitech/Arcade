#pragma once
#include <string>

#include "IlibsDyn.hpp"
#include "tools.hpp"
#include <SDL_ttf.h>
#include <SDL2/SDL.h>
#include <unordered_map>
#include <vector>

class sdlSprite : public Sprite
{
public:
    sdlSprite(SDL_Surface *surface, SDL_Rect rect);
    ~sdlSprite();
    SDL_Surface *_imageSurface;
    SDL_Rect _img_position;
};

class sdlText : public Text
{
public:
    sdlText(SDL_Surface *surface, SDL_Rect rect);
    ~sdlText();
    SDL_Surface *_textSurface;
    SDL_Rect _text_position;
};

class libSdl : public IlibsDyn
{
public:
    libSdl();
    ~libSdl();
    void drawSprite(const Sprite target);
    void drawNum(const int num);
    void drawText(const Text target);
    void playSound(const Sound target);
    void refresh();
    void windowCreate(std::string winName, std::string font);
    void clear();
    void windowDestroy();
    event_t getEvent();
    bool _loop;


    void resetSprite();
    void removeSprite(std::string name, bool all);

    void resetText();
    
    void takeSprite(std::vector<std::pair<std::string, Sprite>>);
    void takeText(std::vector<std::pair<std::string, Text>>);
private:
    bool checkContainsErase(std::string name, std::vector<std::pair<std::string, Sprite>>);
    SDL_Surface *_windowSurface;
    SDL_Event windowEvent;
    std::string _name;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    TTF_Font *_font;
    SDL_Texture *_background;
    unsigned int _score;
    std::unordered_map<std::string, sdlSprite> _spriteMap;
    std::unordered_map<std::string, sdlText> _textMap;
    std::vector<std::pair<std::string, sdlSprite>> _spriteVector;
    std::vector<std::pair<std::string, sdlText>> _textVector;
};

extern "C" IlibsDyn* createLib();
extern "C" void destroyLib(IlibsDyn* p);
