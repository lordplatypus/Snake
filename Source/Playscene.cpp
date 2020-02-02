#include <iostream>
#include <SFML/Graphics.hpp>
#include "/home/bryce/Documents/SFML/Snake/Headers/Playscene.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Map.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/SnakeHead.h"
using namespace sf;
using namespace std;

Playscene::Playscene()
{
    
}

Playscene::~Playscene()
{;
    delete snakeHead;
    delete map;
}

void Playscene::Init()
{
    map = new Map;
    snakeHead = new SnakeHead;
    snakeHead->Init(this);
    map->Init(this);
    //map->PlaceFood();
}

void Playscene::Update()
{
    snakeHead->Update();
}

void Playscene::Draw()
{    
    snakeHead->Draw();
    map->Draw();
}