#include <SFML/Graphics.hpp>
#include <vector>
#include "/home/bryce/Documents/SFML/Snake/Headers/Game.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
using namespace sf;
using namespace std;

vector<CircleShape> LP::circles;
vector<RectangleShape*> LP::rectangles;
map<int, RectangleShape> LP::rectangleMap;
int LP::rectangleMapCount = -1;

LP::LP()
{
    circles.resize(0);
    rectangles.resize(0);
}

LP::~LP()
{
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


int LP::SetRectangle(int x, int y, int size, sf::Color color)
{
    rectangleMapCount++;
    RectangleShape temp;
    temp.setSize(Vector2<float>(size, size));
    temp.setPosition(x, y);
    temp.setFillColor(color);
    //rectangleMap.insert(pair(rectangleMapCount, temp));
    rectangleMap[rectangleMapCount] = temp;
    return rectangleMapCount;
}

void LP::DrawRectangle(int x, int y, int size, sf::Color color, int handle)
{
    RectangleShape* temp;
    temp = &rectangleMap[handle];
    temp->setPosition(x, y);
    temp->setSize(Vector2<float>(size, size));
    temp->setFillColor(color);
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
    if(rectangleMap.size() > 0)
    {
        for (int i = 0; i < rectangleMap.size(); i++)
        {
            window->draw(rectangleMap[i]);
        }
    }
}