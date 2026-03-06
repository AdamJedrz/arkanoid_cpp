#include "Game.h"

int main() {

    sf::Clock clock;
    sf::RenderWindow window(sf::VideoMode(661, 1024), "Arkanoid");


    // Inicjalizacja tła
    sf::Texture background_texture;
    sf::Sprite background;

    if (!background_texture.loadFromFile("../assets/background.png")) {
        std::cerr << "Nie mozna wczytac grafiki!" << std::endl;
        }

    background.setTexture(background_texture);
    background.setPosition(5, 0);
    background.scale(0.8, 0.8);

    // Game over
    sf::Texture background_texture_over;
    sf::Sprite background_over;

    if (!background_texture_over.loadFromFile("../assets/background_over.png")) {
        std::cerr << "Nie mozna wczytac grafiki!" << std::endl;
        }

    background_over.setTexture(background_texture_over);
    background_over.setPosition(5, 0);
    background_over.scale(0.8, 0.8);

    // Piłka i platforma
    Platform platform;
    Ball ball;

    platform.setTexture("../assets/platform.png");
    ball.setTexture("../assets/ball.png");

    ball.setPosition(311, 579);
    ball.setScale(0.03, 0.03);
    platform.setPosition(282, 616);
    platform.setScale(0.1, 0.1);

    double x_rand = 0.0;
    double y_rand = 0.0;
    bool Start = false;
    bool Finish = false;

    while (window.isOpen()) {

        sf::Event event;
        float deltaTime = clock.restart().asSeconds();

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }


        // Start gry
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !Start) {
            Start = true;
            Finish = false;
            ball.setPosition(311, 579);
            platform.setPosition(282, 616);
            ball.setSpeed(300);
            platform.setSpeed(300);
            ball.setXdirection((rand() % 2 == 0) ? 1 : -1);  
        }


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && platform.getPosition().x > LEFT_WALL) {
            platform.getSprite().move(-platform.getSpeed() * deltaTime, 0);
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && platform.getPosition().x < RIGHT_WALL - platform.getBounds().width/2) {
            platform.getSprite().move(platform.getSpeed() * deltaTime, 0);
        }



        if(Start && ball.getPosition().y>800){
            Finish = true;
        };

        if(!Finish){
            sf::Vector2f movement;
            movement.x = ball.getSpeed() * deltaTime * ball.getXdirection();
            movement.y = ball.getSpeed() * deltaTime * ball.getYdirection();
            ball.getSprite().move(movement);

            BallBouncing(&ball);
            BallCollision(&platform, &ball);

            window.clear(sf::Color::Black);
            window.draw(background);
            window.draw(ball.getSprite());
            window.draw(platform.getSprite());
            window.display();
        }
        else{
            Start = false;
            window.clear(sf::Color::Black);
            window.draw(background_over);
            window.display();
        }
    }

    return 0;
}