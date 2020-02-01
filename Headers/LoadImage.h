#ifndef LOAD_IMAGE_H_
#define LOAD_IMAGE_H_
#include <SFML/Graphics/Texture.hpp>

class LoadImage
{
public:
    LoadImage();
    ~LoadImage();
    static void Load();
    static sf::Texture wall;
    static int player;
};

#endif