
#pragma once
#include "entity.h"
#include "enemy.h"
#include "Projectile/projectile.h"
#include "SFML/Graphics.hpp"
#include <functional>

using namespace sf;

class Player: public Entity {
    public:
        Player();
        Player(sf::Vector2f position, sf::Texture texture);
        Sprite sprite;

        Texture texture; 
        Texture left_texture; 
        Texture right_texture; 

        Sprite proj_sprite;
        Texture proj_texture; 
        std::vector<CircleShape> projs; 

        sf::Clock shoot_timer;
        const float MAX_TIME_TO_SHOOT = 0.1;
        float time_to_shoot;
        float movement_speed; 
        bool canShoot;

        void update(float deltaTime) override; 
        void draw (sf::RenderWindow &window) override;

        void set_texture(std::string file_path); 
        void set_position(Vector2f position);
        void spawn_proj();
        void CheckForCollisions (Enemy e);
        std::vector<sf::CircleShape> GetPlayerProjectiles();
        sf::FloatRect GetGlobalBounds();
        sf::Vector2f get_player_position();  
};