#include <iostream>
#include <string>
#include "Player.h"

Player::Player(const std::string &name_in, double servePercentage_in, double returnPercentage_in)
      : name(name_in),
        servePercentage(servePercentage_in),
        returnPercentage(returnPercentage_in) {}

Player::Player() : Player("", 0, 0) {}

Player::Player(const std::string &name_in) : Player(name_in, 0, 0) {}

std::string Player::getName() const{
  return name;
}

double Player::getServePercentage() const{
  return servePercentage;
}

double Player::getReturnPercentage() const{
  return returnPercentage;
}

std::ostream & operator<<(std::ostream &os, const Player &p){
  os << p.getName() << ", Serve: " << p.getServePercentage()
  << ", Return: " << p.getReturnPercentage() << std::endl;
  return os;
}
