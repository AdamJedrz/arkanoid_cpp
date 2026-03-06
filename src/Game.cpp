#include "Game.h"

void GameObject::setTexture(const std::string& path){

            if (!texture.loadFromFile(path)) {
                std::cerr << "Nie mozna wczytac grafiki!" << std::endl;
            }
            sprite.setTexture(texture);
        };


void BallCollision(Platform* platform, Ball* ball){

    if (ball->getBounds().intersects(platform->getBounds())) {
        ball->setYdirection(ball->getYdirection()*(-1));
        };
};


void BallBouncing(Ball* ball){

    if(ball->getPosition().x < LEFT_WALL || ball->getPosition().x > RIGHT_WALL){
        ball->setXdirection(ball->getXdirection()*(-1));
    }

    if(ball->getPosition().y < UP_WALL){
        ball->setYdirection(ball->getYdirection()*(-1));
    }

};





