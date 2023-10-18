
#include "grunt.h"

Grunt::Grunt() {
    GruntTexture.loadFromFile("/Users/alejandroserrano/Desktop/express-server/examples/cpp/Pointers/resources/enemy_3.png");
    Sprite.setTexture(GruntTexture);
    Sprite.setPosition(450, 450); 

}

Grunt::Grunt(sf::Color col, sf::Vector2f position, sf::Vector2f size) 
:Enemy(col, position, size) {

}

Grunt::Grunt(int i) {

}

void Grunt::draw (sf::RenderWindow &window){
    window.draw(Sprite);
};