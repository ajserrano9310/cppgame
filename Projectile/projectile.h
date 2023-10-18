
#pragma once
#include "/Users/alejandroserrano/Desktop/express-server/examples/cpp/Pointers/entity.h"
#include "SFML/Graphics.hpp"
#include "/Users/alejandroserrano/Desktop/express-server/examples/cpp/Pointers/enemy.h"
#include <functional>


using namespace sf;

class Projectile: public Entity {
    public:
        Projectile(); 
        Projectile(sf::Vector2f position); 
        Projectile(sf::Vector2f position, sf::Texture texture);
        sf::Sprite sprite;
        sf::Texture texture;
        sf::CircleShape proj_shape;
        void CheckCollision(class Enemy e);
        void update(float) override; 
        void draw (sf::RenderWindow &window) override;
        void set_sprite(sf::Vector2f position, sf::Texture texture); 
         
};