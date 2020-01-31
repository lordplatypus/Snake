#include <SFML/Graphics.hpp>
#include "/home/bryce/Documents/SFML/Snake/Headers/SnakeHead.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
using namespace sf;

SnakeBody::SnakeBody(int newX, int newY) : x{newX}, y{newY}
{
    x = newX;
    y = newY;
    //body.setFillColor(Color::Blue);
    SetRandomColor();
    Vector2<float> bodySize;
    bodySize.x = CellSize;
    bodySize.y = CellSize;
    body.setSize(bodySize);
    body.setPosition(x, y);
}

SnakeBody::~SnakeBody()
{}

void SnakeBody::SetLocation(int newX, int newY)
{
    x = newX;
    y = newY;
    body.setPosition(x, y);
}

void SnakeBody::SetRandomColor()
{
    srand(time(NULL));
    int randColor = rand() % 4;
    if (randColor == 0) body.setFillColor(Color::Red);
    else if (randColor == 2) body.setFillColor(Color::Yellow);
    else if (randColor == 3) body.setFillColor(Color::Cyan);
    else body.setFillColor(Color::Magenta);
}

Vector2<int> SnakeBody::ReturnLocation()
{
    return Vector2<int>(x, y);
}

void SnakeBody::Draw()
{
    LP::DrawRectangle(&body);
}