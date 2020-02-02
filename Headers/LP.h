#ifndef LP_H_
#define LP_H_
#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>

class LP
{
public:
    LP();
    ~LP();
    static void DrawCircle(sf::CircleShape circle);
    static void DrawCircle(sf::CircleShape circle, int x, int y, sf::Color color, int size);
    static int SetRectangle(int x, int y, int size, sf::Color color);
    static void DrawRectangle(int key);
    static void DrawRectangle(int x, int y, int size, sf::Color color, int key);
    static void Draw(sf::RenderWindow *window);

private:
    static std::vector<sf::CircleShape> circles;
    static std::vector<sf::RectangleShape*> rectangles;
    static std::map<int, sf::RectangleShape> rectangleMap;
    static int rectangleMapCount;
    static std::stack<int> thingsToDraw;
};

#endif