/*
** EPITECH PROJECT, 2019
** def of the interphase of the lib class
** File description:
** created by jooyoung
*/

#pragma once

#include "tools.hpp"
#include <vector>

//================================================================================
// DEFINITION OF THE ILIBDYN
//================================================================================

typedef enum
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    EXIT,
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z,
    F1,
    F2,
    F3,
    F4,
    ENTER,
    SPACE,
    BACK,
    UNKNOWN
} event_t;

class IlibsDyn
{
public:
    virtual ~IlibsDyn() = default;
    virtual void drawSprite(const Sprite target) = 0;
    virtual void drawNum(const int num) = 0;
    virtual void drawText(const Text target) = 0;
    virtual void playSound(const Sound target) = 0;
    virtual void refresh() = 0;
    virtual void windowCreate(std::string winName, std::string font) = 0;
    virtual void clear() = 0;
    virtual void windowDestroy() = 0;
    virtual event_t getEvent() = 0;
    virtual void resetSprite() = 0;
    virtual void removeSprite(std::string name, bool all) = 0;

    virtual void resetText() = 0;

    // MODIFICATION DU LIB DYNAMIQUE, FONCTION CI DESOUS PRENDS UNE VECTOR DE PAIR DE SPRITE
    // EN PARAMETRE ET REMPLIT LE VECTOR DU LIBDYN PAR LE PARAMETRE DONNE

    virtual void takeSprite(std::vector<std::pair<std::string, Sprite>>) = 0;
    virtual void takeText(std::vector<std::pair<std::string, Text>>) = 0;
};

//================================================================================
// DEFINITION OF THE ILIBDYN
//================================================================================

typedef IlibsDyn* create_t();
typedef void destroy_t(IlibsDyn *);
