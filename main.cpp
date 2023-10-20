

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "entity.h"
#include "player.h"
#include "enemy.h"
#include "grunt.h"
#include "Projectile/projectile.h"
#include <stdio.h>
#include "GameConfig.cpp"
#include <functional>
#include <vector>

using namespace sf;
using namespace std;

const string front_text = "/Users/alejandroserrano/Desktop/express-server/examples/cpp/Pointers/resources/02_ship.png";
const string background_path = "/Users/alejandroserrano/Desktop/express-server/examples/cpp/Pointers/resources/desert-backgorund.png";
bool canShoot = true;

class Game
{
public:
  Game();
  void run();
  Entity ent;
  Player play;
  Enemy enemy;
  Grunt grunt;
  Grunt *pointer;

#pragma region Time stuff
  sf::Clock clock;
  sf::Clock shoot_timer;
  const float MAX_TIME_TO_SHOOT = 3.0f;
  float time_to_shoot = MAX_TIME_TO_SHOOT;
  int shot = 0;
#pragma endregion

#pragma region Enemies init
  vector<Enemy *> badGuys;
  void initEnemies();
#pragma endregion

  sf::Texture background_texture;
  sf::Sprite background_sprite;

  void update(float delta_time);
  void draw(sf::RenderWindow &window);
  bool isColliding(Enemy *enemy, CircleShape &projs);

  // std::function<void(std::vector<Enemy>&, int)> onCollision = [](std::vector<CircleShape> &projs, int index)
  // {
  //   std::cout << "the currentsize: " << projs.size() << std::endl;
  //   projs.erase(projs.begin() + index);
  //   // Handle the collision event here...
  //   std::cout << "the updated size: " << projs.size() << std::endl;

  // };

private:
  RenderWindow window;
};

Game::Game() : window(sf::VideoMode(800, 600), "SFML Game")
{
  window.setFramerateLimit(60);
  unsigned int height = sf::VideoMode::getDesktopMode().height;
  unsigned int width = sf::VideoMode::getDesktopMode().width;

  background_texture.loadFromFile(background_path);
  background_sprite.setTexture(background_texture);
  background_sprite.setPosition(0, 0);
  background_sprite.setScale(4, 4);

  initEnemies();
}

void Game::update(float deltaTime)
{
  play.update(deltaTime);
  // grunt.update(deltaTime);

  for (size_t i = 0; i < badGuys.size(); i++)
  {
    badGuys[i]->update(deltaTime);
  }

  for (size_t i = 0; i < play.projs.size(); i++)
  {
    for (size_t j = 0; j < badGuys.size(); j++)
    {
      Enemy *e = badGuys[j];
      bool hasCollided = isColliding(e, play.projs[i]);
      if (hasCollided)
      {
        play.projs.erase(play.projs.begin() + i);
        badGuys.erase(badGuys.begin() + j);
        delete e;
      }
    }
  }
}

void Game::draw(sf::RenderWindow &window)
{
  window.clear();
  // Draw here
  window.draw(background_sprite);
  play.draw(window);

  for (size_t i = 0; i < badGuys.size(); i++)
  {
    badGuys[i]->draw(window);
  }
  window.display();
}

void Game::initEnemies()
{
  Grunt *bg1;
  bg1 = new Grunt;
  badGuys.push_back(bg1);
}

bool Game::isColliding(Enemy *enemy, CircleShape &projectile)
{
  Grunt *g = dynamic_cast<Grunt *>(enemy);
  if (g)
  {
    return projectile.getGlobalBounds().intersects(g->GetCollisionBox());
  }
  return false;
}

void Game::run()
{
  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if (event.type == sf::Event::Closed)
        window.close();
    }
    this->update(clock.restart().asSeconds());
    this->draw(window);
  }
}

int main()
{
  Game game;
  game.run();
  return 0;
}