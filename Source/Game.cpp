#include <SFML/Graphics.hpp>
#include "/home/bryce/Documents/SFML/Snake/Headers/Game.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Playscene.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Titlescene.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LoadImage.h"
using namespace sf;

Scene* Game::scene;

Game::Game()
{}

Game::~Game()
{
    delete scene;
} 

void Game::Init()
{
    LoadImage::Load();
    scene = new Titlescene();
}

void Game::Update()
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