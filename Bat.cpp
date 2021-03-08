#include "Bat.h"
#include "main.h"

Bat::Bat(float startX, float startY) {
    position.x = startX;
    position.y = startY;

    batShape.setSize(sf::Vector2f(100, 10));
    batShape.setPosition(position);
}

FloatRect Bat::getPosition() {
    return batShape.getGlobalBounds();
}

RectangleShape Bat::getShape() {
    return batShape;
}

void Bat::moveLeft() {
    if (position.x > 0) {
        position.x -= batSpeed;
    }
}

void Bat::moveRight() {
    if (position.x + 100 < windowWidth) {
        position.x += batSpeed;
    }
}

void Bat::reset() {
    position.x = windowWidth / 2;
}

void Bat::update() {
    batShape.setPosition(position);
}