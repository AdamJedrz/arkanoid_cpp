#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>

#define LEFT_WALL 60
#define RIGHT_WALL 550
#define UP_WALL 50

class GameObject
{
    protected:
        sf::Texture texture;
        sf::Sprite sprite;
        double speed = 0.0;
        int x_direction = 1;

    public:
        GameObject() = default;
        ~GameObject() = default;
        void setSpeed(double value){speed = value;}
        double getSpeed() const{return speed;}
        void setXdirection(int value){x_direction = value;}
        int getXdirection() const {return x_direction;}
        void setTexture(const std::string& path);
        sf::FloatRect getBounds() const { return sprite.getGlobalBounds(); }
        sf::Vector2f getPosition() const { return sprite.getPosition(); }
        void setPosition(int x, int y) {sprite.setPosition(x, y);}
        void setScale(double x, double y) {sprite.scale(x, y);}
        sf::Sprite& getSprite() { return sprite; }

};



class Platform : public GameObject{        
};


class Ball : public GameObject{

    private:
        int y_direction = -1;

    public:
        void setYdirection(int value){y_direction = value;}
        int getYdirection() const {return y_direction;}

};

void BallCollision(Platform* platform, Ball* ball);
void BallBouncing(Ball* ball);


#endif // GAME_H