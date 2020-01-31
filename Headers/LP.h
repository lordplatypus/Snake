#ifndef LP_H_
#define LP_H_
#include <SFML/Graphics.hpp>
#include <vector>

class LP
{
public:
    LP();
    ~LP();
    static void SetPermanentRectangle(std::string name, sf::RectangleShape rectangle);
    static void DrawCircle(sf::CircleShape circle);
    static void DrawCircle(sf::CircleShape circle, int x, int y, sf::Color color, int size);
    static void DrawRectangle(sf::RectangleShape *rectangle);
    static void Draw(sf::RenderWindow *window);

private:
    static std::vector<sf::CircleShape> circles;
    static std::vector<sf::RectangleShape*> rectangles;
    static std::map<std::string, sf::RectangleShape> rectangleMap;
};

#endif