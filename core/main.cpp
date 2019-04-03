/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** __DES
*/

#include "arcade.hpp"
#include "libSdl.hpp"
#include "loadLib.hpp"
#include "menu.hpp"
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int ac, char **av)
{
    if (ac == 2) {
        menu *game = new menu(av[1]);
        
        srand(getpid());
        game->mainLoop();
    }
    else {
        std::cout << "Usage:" << std::endl;
        std::cout << "./arcade 'lib/libName.so'" << std::endl;
        std::cout << "Error: No matching parameter number." << std::endl;
        return (84);
    }

    return (0);
}
