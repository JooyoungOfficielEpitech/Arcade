/*
** EPITECH PROJECT, 2019
** readDir.hpp
** File description:
** jooyoung.kim@epitech.eu
*/

#include <sys/types.h>
#include <dirent.h>
#include <string>
#include <vector>
#include <iostream>

class readDir
{
public:
    readDir(std::string path, std::string token);
    ~readDir();
    void update();
    std::vector<std::string> fileList;
    std::vector<std::string> filePath;
private:
    std::string _token;
    std::string _path;
};
