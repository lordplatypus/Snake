#include <SFML/Graphics.hpp>
#include <vector>
#include "/home/bryce/Documents/SFML/Snake/Headers/Game.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
using namespace sf;
using namespace std;

vector<CircleShape> LP::circles;
vector<RectangleShape*> LP::rectangles;
map<string, RectangleShape> LP::rectangleMap;

LP::LP()
{
    circles.resize(0);
    rectangles.resize(0);
}

LP::~LP()
{
}

void LP::SetPermanentRectangle(string name, RectangleShape rectangle)
{
    rectangleMap.insert(pair<string, RectangleShape>(name, rectangle));
}

void LP::DrawCircle(CircleShape circle)
{
    circles.push_back(circle);
}

void LP::DrawCircle(CircleShape circle, int x, int y, Color color, int size)
{
    circle.setRadius(size);
    circle.setFillColor(color);
    circle.setPosition(x, y);
    circles.push_back(circle);
}

void LP::DrawRectangle(RectangleShape *rectangle)
{
    rectangles.push_back(rectangle);
}

void LP::Draw(RenderWindow *window)
{
    if (circles.size() > 0)
    {
        int numOfCirclesToDraw = circles.size();
        for (int i = 0; i < numOfCirclesToDraw; i++)
        {
            window->draw(circles[i]);
            circles.pop_back();
        }
    }
    if (rectangles.size() > 0)
    {
        int numOfRectanglesToDraw = rectangles.size();
        for (int i = 0; i < numOfRectanglesToDraw; i++)
        {
            window->draw(*rectangles[i]);
            rectangles.pop_back();
        }
    }
}