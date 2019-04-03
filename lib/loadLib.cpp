/*
** EPITECH PROJECT, 2019
** load lib
** File description:
** jooyoung.kim@epitech.eu
*/

#include "loadLib.hpp"

loadLib::loadLib(std::string libPath)
{
    goo = "hello lib";
    lib = dlopen(libPath.c_str(), RTLD_LAZY);
    if (!lib) {
        std::cout << "lib is not opened: " << dlerror() << std::endl;
        exit(84);
    }
    create_t *create = (create_t *) dlsym(lib, "createLib");
    if (!create) {
        std::cout << "create function not built\n";
        exit(0);
    }
    targetLib = create();
}

loadLib::~loadLib()
{
    destroy_t *destroy = (destroy_t *) dlsym(lib, "destroyLib");

    destroy(targetLib);
    dlclose(lib);
}
