#ifndef SNAKE_HEAD_H_
#define SNAKE_HEAD_H_
#include <SFML/Graphics.hpp>
#include<vector>
#include "Playscene.h"
#include "SnakeBody.h"

class Playscene;

class SnakeHead
{
public:
    SnakeHead();
    ~SnakeHead();
    void Init(Playscene *ps);
    void Update();
    void Move();
    void Draw();
    void SetLocation(int newX, int newY);
    std::vector<SnakeBody*> bodySegments;
private:
    Playscene *playScene;
    int CellSize = 32;
    int move = 32;
    int x;
    int y;
    sf::RectangleShape head;
    std::vector<sf::Vector2<int> > bodyPositions;
    int player;
};

#endif