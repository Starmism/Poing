#include "Bat.h"
#include "Ball.h"
#include <sstream>
#include <SFML/Graphics.hpp>

using namespace sf;

enum State {
    Menu, Game, Lost
};

int windowWidth;
int windowHeight;
int score = 0;
int lives = 3;
State state = State::Menu;
std::stringstream ss;

int main() {
    windowWidth = 1280;
    windowHeight = 720;
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Poing");
    window.setFramerateLimit(144);



    Bat bat(windowWidth / 2, windowHeight - 20);
    Ball ball(windowWidth / 2, 1);

    Text scoreTrack;
    Text livesTrack;
    Font font;
    font.loadFromFile("DS-DIGIT.ttf");
    scoreTrack.setFont(font);
    livesTrack.setFont(font);
    scoreTrack.setCharacterSize(50);
    livesTrack.setCharacterSize(50);
    scoreTrack.setFillColor(Color::White);
    livesTrack.setFillColor(Color::White);
    scoreTrack.setPosition(5, 0);
    livesTrack.setPosition(5, 50);

    Text gameOver;
    gameOver.setFont(font);
    gameOver.setCharacterSize(150);
    gameOver.setFillColor(Color::White);
    gameOver.setPosition((windowWidth / 2) - (668.0 / 2), windowHeight / 2 - 150);

    Text restart;
    restart.setFont(font);
    restart.setCharacterSize(75);
    restart.setFillColor(Color::White);
    restart.setPosition((windowWidth / 2) - (689.0 / 2), windowHeight / 2 + 100);

    Text title;
    title.setFont(font);
    title.setCharacterSize(200);
    title.setFillColor(Color::White);
    title.setPosition((windowWidth / 2) - (456.0 / 2), (windowHeight / 2) - 157.0);

    Text start;
    start.setFont(font);
    start.setCharacterSize(50);
    start.setFillColor(Color::White);
    start.setPosition((windowWidth / 2) - (479.0 / 2), (windowHeight / 2) + 100);
    float startOpacity = 255.0;
    bool down = true;

    RectangleShape gray;
    gray.setSize(Vector2((float) windowWidth, (float) windowHeight));
    gray.setPosition(0,0);
    gray.setFillColor(Color(0, 0, 0, 100));


    while (window.isOpen()) {

        Event event{};
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
        }

        switch (state) {
            case Menu:
                ss.str(std::string());
                ss << "Poing";
                title.setString(ss.str());

                ss.str(std::string());
                ss << "Press \'Space\' to start";
                start.setString(ss.str());
                start.setFillColor(Color(255, 255, 255, startOpacity));


                // Fade the start string in and out like an arcade
                if (down) {
                    startOpacity -= 0.75f;
                    if (startOpacity < 0) {
                        down = !down;
                    }
                } else {
                    startOpacity += 0.75f;
                    if (startOpacity > 255) {
                        down = !down;
                    }
                }

                window.clear(Color(26, 128, 182, 255));
                window.draw(title);
                window.draw(start);

                if (Keyboard::isKeyPressed(Keyboard::Space)) {
                    score = 0;
                    lives = 3;
                    ball.reset();
                    bat.reset();
                    state = State::Game;
                }
                break;

            case Game:
                if (Keyboard::isKeyPressed(Keyboard::Left)) {
                    bat.moveLeft();
                } else if (Keyboard::isKeyPressed(Keyboard::Right)) {
                    bat.moveRight();
                } else if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    state = State::Menu;
                    break;
                }

                // Ball hits the bottom
                if (ball.getPosition().top > windowHeight) {
                    ball.reset();

                    lives--;

                    if (lives < 1) {
                        state = State::Lost;
                    }
                }

                // Ball hits the top
                if (ball.getPosition().top < 0) {
                    ball.reboundBatOrTop();

                    score++;
                }

                // Ball hits the sides
                if (ball.getPosition().left < 0 || ball.getPosition().left + 10 > windowWidth) {
                    ball.reboundSides();
                }

                // Ball hits the bat
                if (ball.getPosition().intersects(bat.getPosition())) {
                    ball.reboundBatOrTop();
                }

                ball.update();
                bat.update();

                ss.str(std::string());
                ss << "Score: " << score;
                scoreTrack.setString(ss.str());

                ss.str(std::string());
                ss << "Lives: " << lives;
                livesTrack.setString(ss.str());

                window.clear(Color(26, 128, 182, 255));
                window.draw(bat.getShape());
                window.draw(ball.getShape());
                window.draw(scoreTrack);
                window.draw(livesTrack);
                break;

            case Lost:
                ss.str(std::string());
                ss << "Game Over!";
                gameOver.setString(ss.str());

                ss.str(std::string());
                ss << "Press \'Up\' to restart";
                restart.setString(ss.str());

                window.clear(Color(26, 128, 182, 255));
                window.draw(bat.getShape());
                window.draw(ball.getShape());
                window.draw(scoreTrack);
                window.draw(livesTrack);

                window.draw(gray);
                window.draw(gameOver);
                window.draw(restart);

                if (Keyboard::isKeyPressed(Keyboard::Up)) {
                    state = State::Menu;
                }
                break;
        }

        window.display();
    }

    return 0;
}
