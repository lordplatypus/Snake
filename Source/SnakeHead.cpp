#include <SFML/Graphics.hpp>
#include "/home/bryce/Documents/SFML/Snake/Headers/SnakeHead.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Playscene.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Titlescene.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Game.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LoadImage.h"
using namespace sf;


SnakeHead::SnakeHead()
{
    // head.setFillColor(Color::Blue);
    // Vector2<float> headSize;
    // headSize.x = CellSize;
    // headSize.y = CellSize;
    // head.setSize(headSize);

    bodyPositions.resize(0);
    bodySegments.resize(0);

    player = LP::SetRectangle(0, 0, 32, Color::Blue);
}

SnakeHead::~SnakeHead()
{
    for (auto i : bodySegments)
    {
        delete i;
    }
}

void SnakeHead::Init(Playscene *ps)
{
    playScene = ps;
}

void SnakeHead::SetLocation(int newX, int newY)
{
    x = newX;
    y = newY;
    //head.setPosition(x, y);
}

void SnakeHead::Update()
{
    if (Keyboard::isKeyPressed(Keyboard::Left))
    {
        move = -CellSize;
        Move();       
    }
    else if (Keyboard::isKeyPressed(Keyboard::Right))
    {
        move = CellSize;
        Move();
    }
    else if (Keyboard::isKeyPressed(Keyboard::Up))
    {
        move = -CellSize;
        Move();
    }
    else if (Keyboard::isKeyPressed(Keyboard::Down))
    {
        move = CellSize;
        Move();
    }
}

void SnakeHead::Move()
{
    if (bodySegments.size() > 0)
    {// if the snake had body segments add their loction to the list
        for (int i = 0; i < bodySegments.size(); i++)
        {
            bodyPositions.push_back(bodySegments[i]->ReturnLocation());
        }
    }
    bodyPositions.push_back(Vector2<int>(x, y));//save head location before moving   

    //actually move
    if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right)) x += move;
    if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::Down)) y += move;
    //head.setPosition(x, y);

    //check loction that the head is moving to
    int locationKey = playScene->map->ReturnLocation(x, y);
    if (locationKey == 3)
    {//if the location has food
        playScene->map->PlaceFood();//move food
        bodySegments.push_back(new SnakeBody(bodyPositions[bodyPositions.size()-1].x, bodyPositions[bodyPositions.size()-1].y));//create new body segment
    }
    if (locationKey == 1)
    {//if the location is a wall
        Game::ChangeScene(new Titlescene);
    }
    for (int i = 0; i < bodyPositions.size(); i++)
    {//if the location is a body segment / lose condition
        if (Vector2<int>(x, y) == bodyPositions[i])
        {
            Game::ChangeScene(new Titlescene);
        }
    }

    if (bodySegments.size() > 0 && bodyPositions.size() > 0)
    {
        for (int i = bodySegments.size() - 1; i >= 0; i--)
        {
            bodySegments[i]->SetLocation(bodyPositions[bodyPositions.size()-1].x, bodyPositions[bodyPositions.size()-1].y);
            bodyPositions.pop_back();
        }
    }

    bodyPositions.clear();
}

void SnakeHead::Draw()
{
    //LP::DrawRectangle(&head);
    LP::DrawRectangle(x, y, 32, Color::Blue, player);
    if (bodySegments.size() > 0)
    {
        for (int i = 0; i < bodySegments.size(); i++)
        {
            bodySegments[i]->Draw();
        }        
    }
}