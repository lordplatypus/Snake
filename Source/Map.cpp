#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "/home/bryce/Documents/SFML/Snake/Headers/Map.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
using namespace std;
using namespace sf;

Map::Map()
{
    walls.resize(0);

    // Vector2<float> length;
    // length.x = CellSize;
    // length.y = CellSize;
    // wall.setSize(length);
    // wall.setFillColor(Color::White);

    // food.setSize(length);
    // food.setFillColor(Color::Green);

    CreateMap();

    food = LP::SetRectangle(0, 0, 32, Color::Green);
    PlaceFood();
}

Map::~Map()
{}

void Map::Init(Playscene *ps)
{
    playScene = ps;
    SetSnakeHead();
}

void Map::Update()
{}

void Map::CreateMap()
{
    //0 = empty
    //1 = wall
    //2 = snake start position
    //3 = food

    vector<int> resize(mapSize); //y
    map.resize(mapSize, resize); //x
    
    for (int x = 0; x < mapSize; x++)
    {
        for (int y = 0; y < mapSize; y++)
        {
            if (x == mapSize - 1 || x == 0 || y == mapSize - 1 || y == 0)
            {
                map[x][y] = 1;
                //wall.setPosition(x*CellSize, y*CellSize);
                //walls.push_back(wall);
                walls.push_back(LP::SetRectangle(x*CellSize, y*CellSize, CellSize, Color::White));
            }
            else if (x == mapSize - 2 && y == mapSize / 2)
            {
                map[x][y] = 2;
            }
            else map[x][y] = 0;
        }
    }
}

void Map::SetSnakeHead()
{
    for (int x = 0; x < mapSize; x++)
    {
        for (int y = 0; y < mapSize; y++)
        {
            if (map[x][y] == 2) 
            {
                playScene->snakeHead->SetLocation(x*CellSize, y*CellSize);
            }
        }
    }
}

void Map::PlaceFood()
{
    map[foodX/CellSize][foodY/CellSize] = 0;
    srand(time(NULL));
    foodX = (rand() % (mapSize-2)) + 1;
    foodY = (rand() % (mapSize-2)) + 1;
    map[foodX][foodY] = 3;
    // food.setPosition(randX* CellSize, randY* CellSize);
    // lastFoodLocX = randX;
    // lastFoodLocY = randY;
    foodX *= CellSize;
    foodY *= CellSize;
}

int Map::ReturnLocation(int x, int y)
{
    int mapX = x / CellSize;
    int mapY = y / CellSize;
    return map[mapX][mapY];
}

void Map::Draw()
{
    for (int i = 0; i < walls.size(); i++)
    {
        LP::DrawRectangle(walls[i]);
    }
    LP::DrawRectangle(foodX, foodY, 32, Color::Green, food);
}