 
#include "player.h"

Player::Player()
{
    left_texture.loadFromFile("/Users/alejandroserrano/Desktop/express-server/examples/cpp/Pointers/resources/00_ship.png");
    right_texture.loadFromFile("/Users/alejandroserrano/Desktop/express-server/examples/cpp/Pointers/resources/03_ship.png");
    
    texture.loadFromFile("/Users/alejandroserrano/Desktop/express-server/examples/cpp/Pointers/resources/02_ship.png");
    sprite.setTexture(texture);
    sprite.setScale(2.f, 2.f);
    sprite.setPosition(800/2, 600/2);
    canShoot = true;
   

    time_to_shoot = MAX_TIME_TO_SHOOT;
    movement_speed = -100;

}
Player::Player(sf::Vector2f position, sf::Texture texture) : Entity(position, texture) {
    
}

sf::FloatRect Player::GetGlobalBounds() {
    return sprite.getGlobalBounds();
}

std::vector<sf::CircleShape> Player::GetPlayerProjectiles() {
    return projs;
}

void Player::update(float deltaTime)
{
    float side_speed = 100.0f; 
    float fwd_speed = 125.0f;
    float bwd_speed = 75.f; 

    float proj_speed = 100.0f;

    bool isMovingStraight = true; 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        // Move the shape down based on the speed and delta time
        isMovingStraight = false;
        sprite.setTexture(right_texture);
        sprite.move(side_speed * deltaTime, 0);

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        // Move the shape up based on the speed and delta time
        isMovingStraight = false;
        sprite.setTexture(left_texture);
        sprite.move(-side_speed * deltaTime, 0 );
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        sprite.move(0, -fwd_speed * deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        sprite.move(0, bwd_speed * deltaTime);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

        if(canShoot) {
            spawn_proj();
            canShoot = false;
        }
    }

    if(!canShoot) {
        time_to_shoot = time_to_shoot - deltaTime;
        if (time_to_shoot <= 0.0f)
        {
            time_to_shoot = MAX_TIME_TO_SHOOT;
            canShoot = true;
        }
    }

    if(isMovingStraight)
    {
        sprite.setTexture(texture); 
    }

    for(int i = 0; i < projs.size(); i++) {
        projs[i].move(0 , movement_speed * deltaTime);
    }
}

void Player::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < projs.size(); i++) {
        window.draw(projs[i]);
    }
    window.draw(sprite);

}

void Player::set_texture(std::string file_path)
{
    texture.loadFromFile(file_path);
    sprite.setTexture(texture);
    sprite.setScale(2.f, 2.f);
}

void Player::set_position(Vector2f position)
{
    sprite.setPosition(position.x, position.y);
}

void Player::spawn_proj()
{
    CircleShape c;
    c.setFillColor(Color::Red);
    c.setRadius(5);
    c.setPosition(this->get_player_position());
    projs.push_back(CircleShape(c));
}

sf::Vector2f Player::get_player_position()
{
    return sprite.getPosition();
}
void Player::CheckForCollisions(Enemy e) {
    // for(int i = 0; i < projs.size(); i++) {
    //     projs[i].CheckCollision(e);
    // }
}