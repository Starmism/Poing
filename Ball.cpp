#include "Ball.h"
#include "main.h"

std::uniform_real_distribution<float> distribution = std::uniform_real_distribution<float>(-2.1, 1.9);

Ball::Ball(float startX, float startY) {
    position.x = startX;
    position.y = startY;

    ballShape.setSize(sf::Vector2f(15, 15));
    ballShape.setPosition(position);

    reset();
}

FloatRect Ball::getPosition() {
    return ballShape.getGlobalBounds();
}

RectangleShape Ball::getShape() {
    return ballShape;
}

void Ball::reboundSides() {
    xVelocity = -xVelocity;
}

void Ball::reboundBatOrTop() {
    position.y -= (yVelocity * 2);
    yVelocity = std::min(-yVelocity * 1.1, 20.0);
    if (yVelocity > 15.0) {
        xVelocity += distribution(generator);
    }
}

void Ball::reset() {
    position.y = 1;
    position.x = windowWidth / 2;

    xVelocity = distribution(generator) + .1;
    yVelocity = std::abs(distribution(generator) + .1);
}

void Ball::update() {
    position.y += yVelocity;
    position.x += xVelocity;

    ballShape.setPosition(position);
}
