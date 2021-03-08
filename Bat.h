#include <SFML/Graphics.hpp>

using namespace sf;

#ifndef RPG_BAT_H
#define RPG_BAT_H

class Bat {
private:
    Vector2f position;
    RectangleShape batShape;
    float batSpeed = 3.0f;

public:
    Bat(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();
    void moveLeft();
    void moveRight();
    void reset();
    void update();
};


#endif //RPG_BAT_H
