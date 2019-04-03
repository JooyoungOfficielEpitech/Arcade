/*
** EPITECH PROJECT, 2019
** head file of the assets classes
** File description:
** create by jooyoung
*/

#pragma once

#include <sstream>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Score
{
public:
    Score(std::string id, int score, const char *);
    ~Score();
    bool fileExist(const char *fileName);
    void writeScore();
    void highestScore();
    const char *_file;
    std::string _highestscore;
    std::vector<std::pair<std::string, int>> _score;
};
