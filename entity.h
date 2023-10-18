
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <functional>

class Entity {
public:
    Entity();
    Entity(sf::Vector2f position, sf::Texture texture);

    using CollisionListener = std::function<void(Entity&, Entity&)>;
    CollisionListener collisionEventHandler;
    void SetCollisionEventHandler(CollisionListener handler); 
    void callCollisionListener(Entity& other);

    sf::Vector2f position; 
    sf::Texture texture; 
    
    virtual void update(float deltaTime);
    virtual void draw (sf::RenderWindow &window); 
};