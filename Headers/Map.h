#ifndef MAP_H_
#define MAP_H_
#include<vector>
#include "Playscene.h"
#include <SFML/Graphics.hpp>

class Playscene;

class Map
{
public:
    Map();
    ~Map();
    void Init(Playscene *ps);
    void Update();
    void CreateMap();
    void PlaceFood();
    int ReturnLocation(int x, int y);
    void SetSnakeHead();
    void Draw();
private:
    Playscene *playScene;
    int mapSize = 20;
    int CellSize = 32;
    int lastFoodLocX = 1;
    int lastFoodLocY = 1;
    std::vector<std::vector<int> > map;
    // std::vector<sf::RectangleShape> walls;
    // sf::RectangleShape wall;
    // sf::RectangleShape food;
    std::vector<int> walls;
    int food;
    int foodX = 0;
    int foodY = 0;
};

#endif