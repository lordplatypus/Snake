#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/Game.h"
using namespace sf;
using namespace std;



int main()
{
    RenderWindow window(VideoMode(1080, 720), "game window");
    //LP lp;
    Game game;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }

            game.Update(&event);
            game.Draw();

            window.clear();
            //lp.Draw(&window);
            LP::Draw(&window);
            window.display();
        }
    }
    game.~Game();
    return EXIT_SUCCESS;
}