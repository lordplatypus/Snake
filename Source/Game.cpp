#include <SFML/Graphics.hpp>
#include "/home/bryce/Documents/SFML/Snake/Headers/Game.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Playscene.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Titlescene.h"
using namespace sf;

Scene* Game::scene;

Game::Game()
{
    scene = new Titlescene();
}

Game::~Game()
{
    scene->~Scene();
}

void Game::Init()
{
}

void Game::Update(Event* event)
{
    scene->Update();
}

void Game::Draw()
{
    scene->Draw();
}

void Game::ChangeScene(Scene* newScene)
{
    delete scene;
    scene = newScene;
    scene->Init();
}