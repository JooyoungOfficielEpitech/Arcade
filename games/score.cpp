//
// EPITECH PROJECT, 2019
// score
// File description:
// score.cpp
//

#include "score.hpp"

Score::Score(std::string id, int score, const char *file)
{
    _score.push_back(std::make_pair(id, score));
    _file = file;
}

Score::~Score()
{
}

bool Score::fileExist(const char *fileName)
{
    std::ifstream infile(fileName);
    return (infile.good());
}

void Score::highestScore()
{
    std::string line;
    std::stringstream ss;
    std::string temp;
    int numb = 0;
    int high = 0;

    if (fileExist(_file) == true) {
        std::ifstream file(_file, std::ios::in);
        while (file) {
            std::getline(file, line);
            ss << line;
            while (!ss.eof()) {
                ss >> temp;
                std::stringstream(temp) >> numb;
                if (numb > high) {
                    high = numb;
                    _highestscore = line;
                }
                temp = "";

            }

            ss.clear();
            if (!file)
                break;}
    }
}

void Score::writeScore()
{
    if (fileExist(_file) == true) {
        std::ofstream file(_file, std::ios::app);
        for (auto it = _score.begin(); it != _score.end(); it++) {
            file << it->first << " " << it->second << std::endl;;
        }
        file.close();
    }
    else  {
        std::ofstream file;
        file.open(_file);

        if (file.is_open()) {
            for (auto it = _score.begin(); it != _score.end(); it++) {
                file << it->first << " " << it->second << std::endl;;
            }
            file.close();
        }
    }
}
