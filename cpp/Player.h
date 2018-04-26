#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Player{
public:
  Player();
  Player(const std::string &name_in);
  Player(const std::string &name_in, double servePercentage_in, double returnPercentage_in);
  std::string getName() const;
  double getServePercentage() const;
  double getReturnPercentage() const;
private:
  std::string name;
  double servePercentage;
  double returnPercentage;
};

std::ostream & operator<<(std::ostream &os, const Player &p);

#endif
