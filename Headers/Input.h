#ifndef INPUT_H_
#define INPUT_H_
#include <SFML/Graphics.hpp>

class Input
{
public:
    Input();
    ~Input();
    static void Init();
    static void Update(bool buttonState, int buttonID);
    static bool GetButton(int buttonID);
    static bool GetButtonDown(int buttonID);
    static bool GetButtonUp(int buttonID);

private:
    static int prevState;
    static int currentState;
};

#endif