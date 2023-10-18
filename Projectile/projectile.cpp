
#include "projectile.h"

Projectile::Projectile() {

}

Projectile::Projectile(sf::Vector2f position) {
    proj_shape.setFillColor(Color::Red);
    proj_shape.setRadius(5);
    this->position = position;
    proj_shape.setPosition(this->position);
}

Projectile::Projectile(sf::Vector2f position, sf::Texture texture):Entity(position, texture) {
    
}

void Projectile::draw(sf::RenderWindow &window) {
    window.draw(proj_shape);
}

void Projectile::update(float deltaTime) {
    proj_shape.move(0, -100 * deltaTime);
}

void Projectile::set_sprite(sf::Vector2f position, sf::Texture texture) {
   
    // this->sprite.setTexture(texture);
    // this->sprite.setPosition(position);
    // this->sprite.setScale(1.f, 1.f);
    
}

void Projectile::CheckCollision(Enemy e){
    // sf::FloatRect projCollision = proj_shape.getGlobalBounds();
    // if(projCollision.intersects(e.shape.getGlobalBounds())) {
    //     std::cout << "INTERSECTED" << std::endl;
    // }
}