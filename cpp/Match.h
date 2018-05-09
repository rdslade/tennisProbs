#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <string>
#include "Player.h"

class MatchPlayer : public Player{
public:
  MatchPlayer();
  MatchPlayer(const std::string &name_in, double servePercentage_in,
              double returnPercentage_in);
  MatchPlayer(const std::string &name_in);
  bool isServer() const;
private:
  bool serve;
  int points;
  int games;
  int sets;
};

class Match{
public:
  Match();
  Match(const MatchPlayer a_in, const MatchPlayer b_in);
private:
  Player a;
  Player b;
  double serverNetP;
};


#endif
