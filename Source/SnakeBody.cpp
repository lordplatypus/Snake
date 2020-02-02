#include <SFML/Graphics.hpp>
#include "/home/bryce/Documents/SFML/Snake/Headers/SnakeHead.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
using namespace sf;

SnakeBody::SnakeBody(int newX, int newY) : x{newX}, y{newY}
{
    x = newX;
    y = newY;
    //body.setFillColor(Color::Blue);
    // SetRandomColor();
    // Vector2<float> bodySize;
    // bodySize.x = CellSize;
    // bodySize.y = CellSize;
    // body.setSize(bodySize);
    // body.setPosition(x, y);
    body = LP::SetRectangle(x, y, 32, SetRandomColor());
}

SnakeBody::~SnakeBody()
{}

void SnakeBody::SetLocation(int newX, int newY)
{
    x = newX;
    y = newY;
    //body.setPosition(x, y);
}

Color SnakeBody::SetRandomColor()
{
    Color color;
    srand(time(NULL));
    int randColor = rand() % 4;
    if (randColor == 0) color = Color::Red;
    else if (randColor == 2) color = Color::Yellow;
    else if (randColor == 3) color = Color::Cyan;
    else color = Color::Magenta;
    return color;
}

Vector2<int> SnakeBody::ReturnLocation()
{
    return Vector2<int>(x, y);
}

void SnakeBody::Draw()
{
    LP::DrawRectangle(x, y, 32, SetRandomColor(), body);
}