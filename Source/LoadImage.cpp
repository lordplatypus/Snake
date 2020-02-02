#include <SFML/Graphics.hpp>
#include "/home/bryce/Documents/SFML/Snake/Headers/LoadImage.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
using namespace sf;

Texture LoadImage::wall;
int LoadImage::player;

LoadImage::LoadImage()
{}

LoadImage::~LoadImage()
{}

void LoadImage::Load()
{
    //wall.loadFromFile("/home/bryce/Documents/SFML/Snake/wall.png");
    //player  = LP::SetRectangle(0, 0, 32, Color::Blue);
}