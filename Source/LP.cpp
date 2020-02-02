#include <SFML/Graphics.hpp>
#include <vector>
#include <stack>
#include "/home/bryce/Documents/SFML/Snake/Headers/Game.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"
using namespace sf;
using namespace std;

vector<CircleShape> LP::circles;
vector<RectangleShape*> LP::rectangles;
map<int, RectangleShape> LP::rectangleMap;
int LP::rectangleMapCount = -1;
stack<int> LP::thingsToDraw;

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

int LP::SetRectangle(int x, int y, int size, sf::Color color)
{
    rectangleMapCount++;
    RectangleShape temp;
    temp.setSize(Vector2<float>(size, size));
    temp.setPosition(x, y);
    temp.setFillColor(color);
    rectangleMap[rectangleMapCount] = temp;
    return rectangleMapCount;
}

void LP::DrawRectangle(int key)
{
    thingsToDraw.push(key);
}

void LP::DrawRectangle(int x, int y, int size, sf::Color color, int key)
{
    RectangleShape* temp;
    temp = &rectangleMap[key];
    temp->setPosition(x, y);
    temp->setSize(Vector2<float>(size, size));
    temp->setFillColor(color);
    thingsToDraw.push(key);
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
    if(thingsToDraw.size() > 0)
    {
        int numOfThingsToDraw = thingsToDraw.size();
        for (int i = 0; i < numOfThingsToDraw; i++)
        {
            window->draw(rectangleMap[thingsToDraw.top()]);
            thingsToDraw.pop();
        }
    }
}