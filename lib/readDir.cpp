/*
** EPITECH PROJECT, 2019
** readDir
** File description:
** joo
*/

#include "../inc/readDir.hpp"

readDir::readDir(std::string path, std::string token)
{
    _path = path;
    _token = token;
    update();
}

void readDir::update()
{
    DIR *folder = opendir(_path.c_str());
    struct dirent *dp;
    std::string target;

    if (!folder) {
        std::cerr << "Error: Directory " << _path << " can't be read." << std::endl;
        exit(84);
    }
    fileList.clear();
    filePath.clear();
    while ((dp = readdir(folder)) != NULL) {
        if (std::string(dp->d_name).find(_token) != std::string::npos) {
            target = std::string(dp->d_name);
            target = target.substr(_token.length(), target.find(".so"));
            target = target.substr(0, target.find(".so"));
            fileList.push_back(target);
            filePath.push_back(_path + std::string(dp->d_name));
        }
    }
    closedir(folder);
}

readDir::~readDir()
{
}
