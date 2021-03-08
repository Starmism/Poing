#include <SFML/Graphics.hpp>
#include <random>

using namespace sf;

#ifndef RPG_BALL_H
#define RPG_BALL_H

class Ball {
private:
    Vector2f position;
    RectangleShape ballShape;
    std::random_device r;
    std::default_random_engine generator{r()};
    float xVelocity;
    float yVelocity;

public:
    Ball(float startX, float startY);
    FloatRect getPosition();
    RectangleShape getShape();
    void reboundSides();
    void reboundBatOrTop();
    void reset();
    void update();
};


#endif //RPG_BALL_H
