#include <SFML/Graphics.hpp>
#include "/home/bryce/Documents/SFML/Snake/Headers/Input.h"
using namespace sf;

int Input::prevState;
int Input::currentState;

Input::Input()
{}

Input::~Input()
{}

void Input::Init()
{
    prevState = false;
    currentState = false;
}

void Input::Update(bool ButtonReleased, int buttonID)
{
    prevState = currentState;
    if (Keyboard::isKeyPressed) currentState = buttonID;
    else currentState = 0;
}

bool Input::GetButton(int buttonID)
{
    return (currentState & buttonID) != 0;
}

bool Input::GetButtonDown(int buttonID)
{
    //return ((currentState & buttonID) & ~(prevState & buttonID)) != 0;
    if (currentState == buttonID && prevState != currentState) return true;
    else return false;
}

bool Input::GetButtonUp(int buttonID)
{
    return ((prevState & buttonID) & ~(currentState & buttonID)) != 0;
}