
#pragma once
#include "entity.h"
class Enemy : Entity {

public:
    Enemy();
    Enemy(sf::Color col, sf::Vector2f position, sf::Vector2f size); 
    Enemy(int i);
    sf::RectangleShape shape; 
    void update(float deltaTime) override; 
    void draw (sf::RenderWindow &window) override;
    sf::FloatRect GetCollisionBox() const;

};