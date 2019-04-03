/*
** EPITECH PROJECT, 2019
** snake
** File description:
** created by jooyoung.kim@epitech.eu
*/

#include "../inc/snakeGame.hpp"
#include "../inc/loadLib.hpp"
#include "../inc/score.hpp"
#include <cstdlib>

extern "C" Igames* createGame(IlibsDyn *lib)
{
    return new snake(lib);
}

extern "C" void destroyGame(Igames * p)
{
    delete p;
}

std::vector<std::pair<std::string, Sprite>> snake::getSpriteVector()
{
    return (_spriteVector);
}

std::vector<std::pair<std::string, Text>> snake::getTextVector()
{
    return (_textVector);
}

snake::snake(IlibsDyn *lib)
{
    Sprite *snake = new Sprite(895, 704, "assets/bmp/snakeHead.bmp", "snake");
    int x = rand() % 450 + 671;
    int y = rand() % 448 + 481;
    Sprite *fruit = new Sprite(x, y, "assets/bmp/bigCell.bmp", "fruit");

    _game = true;
    _name = "snake";
    _lib = lib;
    _loop = true;
    _fruit = fruit;
    _lib->resetSprite();
    _key = 0;
    _previouskey = 0;
    _offset = 2;
    _score = 0;
    _snakebody.push_back(std::make_pair(*snake, _previouskey));
    _size = 0;
    bodyh = "a";
    bodyv = "b";
}

snake::~snake()
{
    delete (_fruit);
    delete (bodyHorz);
    delete (bodyVert);
}

void snake::resetSprite()
{
    _spriteVector.erase(_spriteVector.begin(), _spriteVector.end());
    _textVector.erase(_textVector.begin(), _textVector.end());
}

game_t snake::startGame(event_t event, std::string id)
{
    _id = id;
    resetSprite();
    if (_game == true) {
        drawSprite(Sprite(0, 0, "assets/bmp/background.bmp", "background"));
        drawSprite(Sprite(670, 480, "assets/bmp/ground.bmp", "ground"));
        drawSprite(*_fruit);
        teleport();
        fruit();
        for (auto curr = _snakebody.begin(); curr != _snakebody.end(); curr++) {
            drawSprite(curr->first);
        }
    }
    if (colision() == 1) {
        endGame();
    }
    if (_game == false) {
        drawSprite(Sprite(0, 0, "assets/bmp/background.bmp", "background"));
        drawText(Text(670, 480, 100, "GAME OVER"));
        drawText(Text(835, 600, 200, std::to_string(_score)));
    }
    handleEvent(event);
    if (_loop == false) {
        _spriteVector.clear();
        _textVector.clear();
        _snakebody.clear();
        return (MENU);
    }
    else {
        return (SNAKE);
    }
}

void snake::endGame()
{
    Score score(_id, _score, "score/nibblerScore");
    _game = false;
    resetSprite();

    score.writeScore();
    score.highestScore();
}

int snake::colision()
{
    if ((_previouskey == 3 && _key == 4) || (_previouskey == 4 && _key == 3))
        return (1);
    if ((_previouskey == 1 && _key == 2) || (_previouskey == 2 && _key == 1))
        return (1);
    return (0);
}

void snake::bodyCreate()
{
    auto curr = _snakebody.begin();
    for (int i = 0; i != _size; i++)
        curr++;
    if (_key == 3)
        bodyHorz = new Sprite(curr->first.x - 24, curr->first.y, "assets/bmp/snakeBody.bmp", bodyh);
    if (_key == 4)
        bodyHorz = new Sprite(curr->first.x + 24, curr->first.y, "assets/bmp/snakeBody.bmp", bodyh + "a");
    if (_key == 1)
        bodyVert = new Sprite(curr->first.x, curr->first.y + 24, "assets/bmp/snakeBody.bmp", bodyv);
    if (_key == 2)
        bodyVert = new Sprite(curr->first.x, curr->first.y - 24, "assets/bmp/snakeBody.bmp", bodyv + "a");
}

void snake::fruit()
{
    int x = rand() % 450 + 671;
    int y = rand() % 448 + 481;

    bodyCreate();
    auto curr = _snakebody.begin();
    if ((curr->first.x >= _fruit->x && curr->first.x <= _fruit->x + 25 && curr->first.y >= _fruit->y && curr->first.y <= _fruit->y + 25) || (curr->first.x + 25 >= _fruit->x && curr->first.x + 25 <= _fruit->x + 25 && curr->first.y + 25 >= _fruit->y && curr->first.y + 25 <= _fruit->y + 25)) {
        if (_key == 1 || _key == 2)
            _snakebody.push_back(std::make_pair(*bodyVert, _previouskey));
        if (_key == 3 || _key == 4)
            _snakebody.push_back(std::make_pair(*bodyHorz, _previouskey));
        bodyv += "b";
        bodyh += "a";
        _fruit->x = x;
        _fruit->y = y;
        _offset += 0.2;
        _score += 100;
        _size += 1;
    }
    drawText(Text(1650, 800, 100, std::to_string(_score)));
}

void snake::teleport()
{
    for (auto curr = _snakebody.begin(); curr != _snakebody.end(); curr++) {
        if (curr->first.x < 670)
            curr->first.x = 1120;
        if (curr->first.x > 1120)
            curr->first.x = 670;
        if (curr->first.y < 480)
            curr->first.y = 928;
        if (curr->first.y > 928)
            curr->first.y = 480;
    }
}

void snake::gameLoop()
{
}

void snake::uiLoop()
{
}

void snake::mainLoop()
{
}

std::string snake::getName()
{
    return (_name);
}

void snake::handleEvent(event_t event)
{
    _previouskey = _key;
    evt = event;
    if (evt == ENTER)
        _loop = false;
    if (evt == EXIT) {
        exit(0);
    }
    if (!_snakebody.empty()) {
        auto curr = _snakebody.begin();
        if (evt == UP) {
            removeSprite("snake", false);
            curr->first.path = "assets/bmp/snakeHead.bmp";
            drawSprite(curr->first);
            _key = 1;
        }
        if (evt == DOWN) {
            removeSprite("snake", false);
            curr->first.path = "assets/bmp/snakeHead.bmp";
            drawSprite(curr->first);
            _key = 2;
        }
        if (evt == RIGHT) {
            removeSprite("snake", false);
            curr->first.path = "assets/bmp/snakeHead.bmp";
            drawSprite(curr->first);
            _key = 3;
        }
        if (evt == LEFT) {
            removeSprite("snake", false);
            curr->first.path = "assets/bmp/snakeHead.bmp";
            drawSprite(curr->first);
            _key = 4;
        }
        auto it = _snakebody.begin();
        for (auto curr = _snakebody.begin(); curr != _snakebody.end(); curr++) {
            if (_key == 1) {
                if (curr > it) {
                    if (curr->second == 3) {
                        if (curr->first.x < it->first.x) {
                            curr->first.y += _offset;
                            curr->first.x += _offset;
                        }
                        if (curr->first.x >= it->first.x)
                            curr->second = _key;
                    }
                    if (curr->second == 4) {
                        if (curr->first.x > it->first.x) {
                            curr->first.y += _offset;
                            curr->first.x -= _offset;
                        }
                        if (curr->first.x <= it->first.x)
                            curr->second = _key;
                    }
                }
                curr->first.y -= _offset;
            }
            if (_key == 2) {
                if (curr > it) {
                    if (curr->second == 3) {
                        if (curr->first.x < it->first.x) {
                            curr->first.y -= _offset;
                            curr->first.x += _offset;
                        }
                        if (curr->first.x >= it->first.x)
                            curr->second = _key;
                    }
                    if (curr->second == 4) {
                        if (curr->first.x > it->first.x) {
                            curr->first.y -= _offset;
                            curr->first.x -= _offset;
                        }
                        if (curr->first.x <= it->first.x)
                            curr->second = _key;
                    }
                }
                curr->first.y += _offset;
            }
            if (_key == 3) {
                if (curr > it) {
                    if (curr->second == 1) {
                        if (curr->first.y > it->first.y) {
                            curr->first.x -= _offset;
                            curr->first.y -= _offset;
                        }
                        if (curr->first.y <= it->first.y)
                            curr->second = _key;
                    }
                    if (curr->second == 2) {
                        if (curr->first.y < it->first.y) {
                            curr->first.x -= _offset;
                            curr->first.y += _offset;
                        }
                        if (curr->first.y >= it->first.y)
                            curr->second = _key;
                    }
                }
                curr->first.x += _offset;
            }
            if (_key == 4) {
                if (curr > it) {
                    if (curr->second == 1) {
                        if (curr->first.y > it->first.y) {
                            curr->first.x += _offset;
                            curr->first.y -= _offset;
                        }
                        if (curr->first.y <= it->first.y)
                            curr->second = _key;
                    }
                    if (curr->second == 2) {
                        if (curr->first.y < it->first.y) {
                            curr->first.x += _offset;
                            curr->first.y += _offset;
                        }
                        if (curr->first.y >= it->first.y)
                            curr->second = _key;
                    }
                }
                curr->first.x -= _offset;
            }
            if (curr > it)
                it++;
        }
/*
  auto it = _snakebody.begin();
  for (; curr != _snakebody.end(); curr++) {
  curr->second = _previouskey;
  if (_key == 1) {
  if (curr->second == 3) {
  it->first.y -= 10;
  if (curr != _snakebody.begin()) {
  curr->first.x += 22;
  removeSprite(curr->first.name, false);
  curr->first.path = "assets/bmp/snakeBodyVert.bmp";
  drawSprite(curr->first);
  }
  }
  if (curr->second == 4) {
  it->first.y -= 10;
  if (curr != _snakebody.begin()) {
  curr->first.x -= 22;
  removeSprite(curr->first.name, false);
  curr->first.path = "assets/bmp/snakeBodyVert.bmp";
  drawSprite(curr->first);
  }
  }
  curr->first.y -= _offset;
  }
  if (_key == 2) {
  if (curr->second == 3) {
  it->first.y += 10;
  if (curr != _snakebody.begin()) {
  curr->first.x += 22;
  removeSprite(curr->first.name, false);
  curr->first.path = "assets/bmp/snakeBodyVert.bmp";
  drawSprite(curr->first);
  }
  }
  if (curr->second == 4) {
  it->first.y += 10;
  if (curr != _snakebody.begin()) {
  curr->first.x -= 22;
  removeSprite(curr->first.name, false);
  curr->first.path = "assets/bmp/snakeBodyVert.bmp";
  drawSprite(curr->first);
  }
  }
  curr->first.y += _offset;
  }
  if (_key == 3) {
  if (curr->second == 1) {
  it->first.x += 10;
  if (curr != _snakebody.begin()) {
  curr->first.y -= 22;
  removeSprite(curr->first.name, false);
  curr->first.path = "assets/bmp/snakeBodyHorz.bmp";
  drawSprite(curr->first);
  }
  }
  if (curr->second == 2) {
  it->first.x += 10;
  if (curr != _snakebody.begin()) {
  curr->first.y += 22;
  removeSprite(curr->first.name, false);
  curr->first.path = "assets/bmp/snakeBodyHorz.bmp";
  drawSprite(curr->first);
  }
  }
  curr->first.x += _offset;
  }
  if (_key == 4) {
  if (curr->second == 1) {
  it->first.x -= 10;
  if (curr != _snakebody.begin()) {
  curr->first.y -= 22;
  removeSprite(curr->first.name, false);
  curr->first.path = "assets/bmp/snakeBodyHorz.bmp";
  drawSprite(curr->first);
  }
  }
  if (curr->second == 2) {
  it->first.x -= 10;
  if (curr != _snakebody.begin()) {
  curr->first.y += 22;
  removeSprite(curr->first.name, false);
  curr->first.path = "assets/bmp/snakeBodyHorz.bmp";
  drawSprite(curr->first);
  }
  }
  curr->first.x -= _offset;
  }
  curr->second = _key;
  } */
    }
}

void snake::removeSprite(std::string name, bool all)
{
    for (auto it = _spriteVector.begin(); it != _spriteVector.end(); it++) {
        if (all) {
            if (it->first.find(name) != std::string::npos) {
                it = _spriteVector.erase(it);
                break;
            }
        } else {
            if (it->first == name) {
                it = _spriteVector.erase(it);
                break;
            }
        }
    }
}

void snake::drawSprite(Sprite target)
{
    auto it = _spriteVector.begin();

    while (it != _spriteVector.end()) {
        if (it->first == target.name)
            break;
        else
            it++;
    }
    if (it == _spriteVector.end())
        _spriteVector.push_back(std::make_pair(target.name, target));
    else {
        it->second.x = target.x;
        it->second.y = target.y;
    }
}

void snake::drawText(Text target)
{
    _textVector.push_back(std::make_pair(target.str, target));
}
