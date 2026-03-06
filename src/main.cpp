#include <iostream>
#include <cstdint>
#include <memory>
#include <vector>
#include <stack>
#include <map>
#include <SFML/Graphics.hpp>

#include <SFML/Graphics.hpp>
#include <iostream>



int main() {
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Grafika Test");

    sf::Texture ball_texture;
    sf::Clock clock;


    if (!ball_texture.loadFromFile("../assets/ball.png")) {
        std::cerr << "Nie mozna wczytac grafiki!" << std::endl;
        return -1;
    }

    sf::Sprite ball;
    ball.setTexture(ball_texture);
    ball.setPosition(0, 0);
    ball.scale(0.05, 0.05);

    while (window.isOpen()) {
        sf::Event event;
        float deltaTime = clock.restart().asSeconds();
        float speed = 300;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            ball.move(-speed * deltaTime, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            ball.move(speed * deltaTime, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            ball.move(0, speed * deltaTime);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            ball.move(0, -speed * deltaTime);
        }



        window.clear(sf::Color::Black);
        window.draw(ball);
        window.display();
    }

    return 0;
}