#ifndef TITLESCENE_H_
#define TITLESCENE_H_
#include "/home/bryce/Documents/SFML/Snake/Headers/Scene.h"
#include "/home/bryce/Documents/SFML/Snake/Headers/LP.h"

class Titlescene : public Scene
{
public:
    Titlescene();
    ~Titlescene() override;
    void Init() override;
    void Update() override;
    void Draw() override;

private:
};

#endif