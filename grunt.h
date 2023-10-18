#pragma once
#include "enemy.h"
#include "SFML/Graphics.hpp"
using namespace sf;

class Grunt: public Enemy {
    public:
    Grunt();
    Grunt(sf::Color col, sf::Vector2f position, sf::Vector2f size); 
    Grunt(int i); 
    sf::Texture GruntTexture; 
    sf::Sprite Sprite;
    void draw(sf::RenderWindow &window);
    
};


