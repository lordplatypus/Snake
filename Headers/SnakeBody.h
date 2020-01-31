#ifndef SNAKE_BODY_H_
#define SNAKE_BODY_H_
#include<vector>
#include <SFML/Graphics.hpp>

class SnakeBody
{
public:
    SnakeBody(int newX, int newY);
    ~SnakeBody();
    void SetLocation(int newX, int newY);
    void SetRandomColor();
    sf::Vector2<int> ReturnLocation();
    void Draw();
private:
    sf::RectangleShape body;
    int CellSize = 32;
    int move = 32;
    int x;
    int y;
};

#endif