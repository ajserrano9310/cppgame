
#include "enemy.h"

Enemy::Enemy() {
    shape.setFillColor(sf::Color::Cyan);
    shape.setSize(sf::Vector2f(20, 20));
    shape.setPosition(sf::Vector2f(200, 200));
}

Enemy::Enemy(sf::Color col, sf::Vector2f position, sf::Vector2f size){
    shape.setFillColor(col);
    shape.setSize(size);
    shape.setPosition(position);
}

Enemy::Enemy(int i) {
    std::cout << "Hello, the number is: " << i << std::endl;
}

void Enemy::update(float deltaTime) {
    shape.move(0, 25 * deltaTime);
}

void Enemy::draw (sf::RenderWindow &window) {
    window.draw(shape);
}

sf::FloatRect Enemy::GetCollisionBox() const {
    return shape.getGlobalBounds();
}