#include <SFML/Graphics.hpp>
#include "/home/bryce/Documents/SFML/Snake/Headers/SnakeHead.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
using namespace sf;

SnakeBody::SnakeBody(int newX, int newY) : x{newX}, y{newY}
{
    x = newX;
    y = newY;
    body.setFillColor(Color::Blue);
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

Vector2<int> SnakeBody::ReturnLocation()
{
    return Vector2<int>(x, y);
}

void SnakeBody::Draw()
{
    LP::DrawRectangle(&body);
}