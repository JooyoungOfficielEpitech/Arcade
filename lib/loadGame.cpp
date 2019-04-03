/*
** EPITECH PROJECT, 2019
** load lib
** File description:
** jooyoung.kim@epitech.eu
*/

#include "loadGame.hpp"

loadGame::loadGame(std::string libPath, IlibsDyn *lib)
{
    game = dlopen(libPath.c_str(), RTLD_LAZY);
    if (!game) {
        std::cout << "game is not opened: " << dlerror() << std::endl;
        exit(84);
    }
    create_game *create = (create_game *) dlsym(game, "createGame");
    if (!create) {
        std::cout << "create function not built " << dlerror() << std::endl;
        exit(84);
    }
    targetGame = create(lib);
    targetLib = lib;
}

loadGame::~loadGame()
{
    destroy_game *destroy = (destroy_game *) dlsym(game, "destroyGame");

    destroy(targetGame);
    dlclose(game);
}
