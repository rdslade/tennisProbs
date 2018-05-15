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
  int getSets() const;
  int getGames() const;
  int getPoints() const;
  void setServe(bool s);
  void winPoint();
  void winGame();
  void winSet();
  void resetGame();
  void resetSet();
  void setDuece();
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
  MatchPlayer & getPlayer(int index);
  void resetGame();
  void resetSet();
  void setDuece();
  double getServerGameProb(const MatchPlayer &server, const MatchPlayer &returner) const;
  double getCurrentGameProb() const;
  void setServerNetP();
private:
  MatchPlayer a;
  MatchPlayer b;
  double serverNetP;
};

std::ostream& operator<<(std::ostream& os, Match& m);


#endif
