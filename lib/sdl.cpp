/*
** EPITECH PROJECT, 2019
** lib for sdl
** File description:
** jooyoung.kim@epitech.eu
*/

#include "libSdl.hpp"
#include <SDL2/SDL.h>
#include "SDL_image.h"
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//========================================================================================
// DEFINITION OF THE SDLSPRITE
//========================================================================================

sdlSprite::sdlSprite(SDL_Surface *surface, SDL_Rect rect) : _imageSurface(surface), _img_position(rect)
{
}

sdlSprite::~sdlSprite()
{
}

//========================================================================================
// DEFINITION OF THE SDLSPRITE
//========================================================================================


//========================================================================================
// DEFINITION OF THE SDLTEXT
//========================================================================================

sdlText::sdlText(SDL_Surface *surface, SDL_Rect rect) : _textSurface(surface), _text_position(rect)
{
}

sdlText::~sdlText()
{
}

//========================================================================================
// DEFINITION OF THE SDLTEXT
//========================================================================================

//========================================================================================
// DEFINITION OF THE SDL
//========================================================================================

libSdl::libSdl()
{
    _loop = true;
}

void libSdl::drawSprite(const Sprite target)
{
    SDL_Surface *imageSurface;
    SDL_Rect m_image_position;

    m_image_position.x = target.x;
    m_image_position.y = target.y;
    auto it = _spriteVector.begin();
    while (it != _spriteVector.end()) {
        if (it->first == target.name)
            break;
        it++;
    }
    if (it != _spriteVector.end())
        // 경우의 수 2번
        it->second._img_position = m_image_position;
    else {
        //경우의 수 1번
        imageSurface = SDL_LoadBMP(target.path.c_str());
        if (!imageSurface)
            std::cout << "Error, cannot open the file: " << target.path.c_str() << std::endl;
        _spriteVector.push_back(std::make_pair(target.name, sdlSprite(imageSurface, m_image_position)));
    }
}

void libSdl::drawNum(const int num)
{
    drawText(Text(0, 0, 100, std::to_string(num)));
}

void libSdl::drawText(const Text target)
{
    SDL_Surface *textSurface;
    SDL_Rect m_text_position;
    SDL_Color white = {255, 255, 255, 255};
    
    m_text_position.x = target.x;
    m_text_position.y = target.y;
    auto it = _textMap.begin();
    while (it != _textMap.end()) {
        if (it->first == target.str)
            break;
        it++;
    }
    if (it != _textMap.end())
        _textMap.at(target.str)._text_position = m_text_position;
    else {
        textSurface = TTF_RenderText_Blended(_font, target.str.c_str(), white);
        _textMap.insert(std::make_pair(target.str, sdlText(textSurface, m_text_position)));
    }
}

void libSdl::playSound(const Sound target)
{
}

void libSdl::refresh()
{
    for (auto curr = _spriteVector.begin(); curr != _spriteVector.end(); curr++) {
        SDL_BlitSurface(curr->second._imageSurface, NULL, _windowSurface, &curr->second._img_position);
    }
    for (auto curr = _textMap.begin(); curr != _textMap.end(); curr++) {
        SDL_BlitSurface(curr->second._textSurface, NULL, _windowSurface, &curr->second._text_position);
    }
    SDL_RenderPresent(_renderer);
    SDL_UpdateWindowSurface(_window);
}

void libSdl::windowCreate(std::string winName, std::string font)
{
    int i = 0;
    int j = 0;
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        exit(84);
    _window = SDL_CreateWindow(winName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_SHOWN);
    if (!_window)
        exit(84);
    if ((_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED)) == NULL)
        exit(84);
    if ((_windowSurface = SDL_GetWindowSurface(_window)) == nullptr)
        exit(84);
    if (TTF_Init() != 0)
        exit(84);
    _font = TTF_OpenFont(font.c_str(), 100);
    if (!_font)
        std::cout << "Error, no open file ttf\n";
    _background = IMG_LoadTexture(_renderer, "img/test.png");
}

void libSdl::clear()
{
    SDL_FillRect(_windowSurface, NULL, SDL_MapRGB(_windowSurface->format, 0, 0, 0));
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
    SDL_RenderClear(_renderer);
}

void libSdl::windowDestroy()
{
    SDL_DestroyRenderer(_renderer);
    _renderer = nullptr;
    SDL_DestroyWindow(_window);
    TTF_CloseFont(_font);
    TTF_Quit();
    SDL_Quit();
}

event_t libSdl::getEvent()
{
    if (SDL_PollEvent(&windowEvent)) {
        if (SDL_QUIT == windowEvent.type)
            return (EXIT);
        if (windowEvent.type == SDL_KEYDOWN) {
            if (windowEvent.key.keysym.sym == SDLK_UP)
                return (UP);
            if (windowEvent.key.keysym.sym == SDLK_DOWN)
                return (DOWN);
            if (windowEvent.key.keysym.sym == SDLK_LEFT)
                return (LEFT);
            if (windowEvent.key.keysym.sym == SDLK_RIGHT)
                return (RIGHT);
        }
        if (windowEvent.type == SDL_KEYUP) {
            if (windowEvent.key.keysym.sym == SDLK_a)
                return (A);
            if (windowEvent.key.keysym.sym == SDLK_b)
                return (B);
            if (windowEvent.key.keysym.sym == SDLK_c)
                return (C);
            if (windowEvent.key.keysym.sym == SDLK_d)
                return (D);
            if (windowEvent.key.keysym.sym == SDLK_e)
                return (E);
            if (windowEvent.key.keysym.sym == SDLK_f)
                return (F);
            if (windowEvent.key.keysym.sym == SDLK_g)
                return (G);
            if (windowEvent.key.keysym.sym == SDLK_h)
                return (H);
            if (windowEvent.key.keysym.sym == SDLK_i)
                return (I);
            if (windowEvent.key.keysym.sym == SDLK_j)
                return (J);
            if (windowEvent.key.keysym.sym == SDLK_k)
                return (K);
            if (windowEvent.key.keysym.sym == SDLK_l)
                return (L);
            if (windowEvent.key.keysym.sym == SDLK_m)
                return (M);
            if (windowEvent.key.keysym.sym == SDLK_n)
                return (N);
            if (windowEvent.key.keysym.sym == SDLK_o)
                return (O);
            if (windowEvent.key.keysym.sym == SDLK_p)
                return (P);
            if (windowEvent.key.keysym.sym == SDLK_q)
                return (Q);
            if (windowEvent.key.keysym.sym == SDLK_r)
                return (R);
            if (windowEvent.key.keysym.sym == SDLK_s)
                return (S);
            if (windowEvent.key.keysym.sym == SDLK_t)
                return (T);
            if (windowEvent.key.keysym.sym == SDLK_u)
                return (U);
            if (windowEvent.key.keysym.sym == SDLK_v)
                return (V);
            if (windowEvent.key.keysym.sym == SDLK_w)
                return (W);
            if (windowEvent.key.keysym.sym == SDLK_x)
                return (X);
            if (windowEvent.key.keysym.sym == SDLK_y)
                return (Y);
            if (windowEvent.key.keysym.sym == SDLK_z)
                return (Z);
            if (windowEvent.key.keysym.sym == SDLK_F1)
                return (F1);
            if (windowEvent.key.keysym.sym == SDLK_F2)
                return (F2);
            if (windowEvent.key.keysym.sym == SDLK_F3)
                return (F3);
            if (windowEvent.key.keysym.sym == SDLK_F4)
                return (F4);
            if (windowEvent.key.keysym.sym == SDLK_ESCAPE)
                return (EXIT);
            if (windowEvent.key.keysym.sym == SDLK_RETURN) {
                return (ENTER);
            }
            if (windowEvent.key.keysym.sym == SDLK_BACKSPACE) {
                return (BACK);
            }
            if (windowEvent.key.keysym.sym == SDLK_SPACE) {
                return (SPACE);
            }
        }
    }
    return (UNKNOWN);
}

libSdl::~libSdl()
{
    windowDestroy();
}

void libSdl::resetSprite()
{
    _spriteVector.erase(_spriteVector.begin(), _spriteVector.end());
}

void libSdl::removeSprite(std::string name, bool all)
{
    for (auto it = _spriteVector.begin(); it != _spriteVector.end(); it++) {
        if (all) {
            if (it->first.find(name) != std::string::npos) {
                it = _spriteVector.erase(it);
                break;
            }
        }
        else
            if (it->first == name) {
                it = _spriteVector.erase(it);
                break;
            }
    }
}

bool libSdl::checkContainsErase(std::string name, std::vector<std::pair<std::string, Sprite>> target)
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

void libSdl::takeSprite(std::vector<std::pair<std::string, Sprite>> target)
{
    if (target.empty()) {
        resetSprite();
        return;
    }
//    std::cout << "Checking the content of the SpriteVector in takeSprite() \n";
    for (auto it = _spriteVector.begin(); it != _spriteVector.end(); it++) {
        if (checkContainsErase(it->first, target))
            it = _spriteVector.begin();
    }
//    std::cout << "\n\n\n\n";
    for (auto it_target = target.begin(); it_target != target.end(); it_target++) {
        drawSprite(it_target->second);
    }
}

void libSdl::takeText(std::vector<std::pair<std::string, Text>> target)
{
    for (auto it = target.begin(); it != target.end(); it++) {
        drawText(it->second);
    }
}

void libSdl::resetText()
{
    _textVector.erase(_textVector.begin(), _textVector.end());
    _textMap.erase(_textMap.begin(), _textMap.end());
}

//========================================================================================
// DEFINITION OF THE SDL
//========================================================================================

extern "C" IlibsDyn* createLib()
{
    return new libSdl;
}

extern "C" void destroyLib(IlibsDyn * p)
{
    delete p;
}
