
#include "grunt.h"

Grunt::Grunt() {
    GruntTexture.loadFromFile("/Users/alejandroserrano/Desktop/express-server/examples/cpp/Pointers/resources/enemy_3.png");
    Sprite.setTexture(GruntTexture);
    Sprite.setPosition(400, 200); 
}

Grunt::Grunt(sf::Color col, sf::Vector2f position, sf::Vector2f size) 
:Enemy(col, position, size) {

}

void Grunt::draw (sf::RenderWindow &window){
    window.draw(Sprite);
};

void Grunt::update(float deltaTime){
    Sprite.move(0, 50 * deltaTime);
}

sf::FloatRect Grunt::GetCollisionBox() const {
    return Sprite.getGlobalBounds();
}