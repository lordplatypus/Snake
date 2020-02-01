#ifndef GAME_H_
#define GAME_H_
#include <SFML/Graphics.hpp>
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Scene.h"

class Game
{
public:
    Game();
    ~Game();
    void Init();
    void Update();
    void Draw();
    void ChangeScene();
    static void ChangeScene(Scene* newScene);

private:
    static Scene* scene;
};

#endif