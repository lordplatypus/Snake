#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Game.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Input.h"
using namespace sf;
using namespace std;



int main()
{
    RenderWindow window(VideoMode(1080, 720), "game window");
    window.setKeyRepeatEnabled(false);
    Game game;
    game.Init();

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            game.Update();
            game.Draw();

            window.clear();
            LP::Draw(&window);
            window.display();
        }
    }
    game.~Game();
    return EXIT_SUCCESS;
}