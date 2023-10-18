#pragma once
#include "entity.h"
#include <SFML/Graphics.hpp>

using CollisionListener = std::function<void(Entity&, Entity&)>;

Entity::Entity()
{

}

Entity::Entity(sf::Vector2f position, sf::Texture texture)
{
    this->position = position; 
    this->texture = texture;
}

void Entity::update(float deltaTime)
{
    
}

void Entity::draw(sf::RenderWindow &window)
{
    
}

void SetCollisionEventHandler(CollisionListener handler) {

}