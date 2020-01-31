#ifndef PLAYSCENE_H_
#define PLAYSCENE_H_
#include "Scene.h"
#include "Map.h"
#include "SnakeHead.h"

class Map;
class SnakeHead;

class Playscene : public Scene
{
public:
    Playscene();
    ~Playscene() override;
    void Init() override;
    void Update() override;
    void Draw() override;
    Map *map;
    SnakeHead *snakeHead;
};

#endif