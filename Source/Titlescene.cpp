#include <iostream>
#include "/home/bryce/Documents/SFML/Snake/Headers/Titlescene.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Playscene.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Game.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Input.h"
using namespace sf;

Titlescene::Titlescene()
{

}

Titlescene::~Titlescene()
{
}

void Titlescene::Init()
{

}

void Titlescene::Update()
{
    // if (Keyboard::isKeyPressed(Keyboard::Z))
    // {
    //     Game::ChangeScene(new Playscene());
    // }

    if (Keyboard::isKeyPressed(Keyboard::Z))
    {
        Game::ChangeScene(new Playscene());
    }
}

void Titlescene::Draw()
{

}