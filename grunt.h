#pragma once
#include "enemy.h"
#include "SFML/Graphics.hpp"

class Grunt: public Enemy {
    public:
    Grunt();
    Grunt(sf::Color col, sf::Vector2f position, sf::Vector2f size); 
    sf::Texture GruntTexture; 
    sf::Sprite Sprite;
    void draw(sf::RenderWindow &window);
    void update(float deltaTime) override;
    sf::FloatRect GetCollisionBox() const;
    
};



 