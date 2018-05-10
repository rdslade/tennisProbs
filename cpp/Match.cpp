#include <iostream>
#include <string>
#include "Match.h"
#include "Player.h"
#include "stats.h"
#include <iomanip>

/* -------------------------------------------------------------------------- */
MatchPlayer::MatchPlayer()
  : Player(), serve(false), points(0), games(0), sets(0){}
MatchPlayer::MatchPlayer(const std::string &name_in, double servePercentage_in,
                        double returnPercentage_in)
  : Player(name_in, servePercentage_in, returnPercentage_in), serve(false),
  points(0), games(0), sets(0){}
MatchPlayer::MatchPlayer(const std::string &name_in)
  : Player(name_in), serve(false), points(0), games(0), sets(0) {}
bool MatchPlayer::isServer() const{
  return serve;
}
int MatchPlayer::getSets() const{
  return sets;
}
int MatchPlayer::getGames() const{
  return games;
}
int MatchPlayer::getPoints() const{
  return points;
}
void MatchPlayer::setServe(bool s){
  serve = s;
}
/* -------------------------------------------------------------------------- */
Match::Match() : a(MatchPlayer()), b(MatchPlayer()), serverNetP(0) {}
Match::Match(const MatchPlayer a_in, const MatchPlayer b_in)
  : a(a_in), b(b_in), serverNetP(0) {}
MatchPlayer & Match::getPlayer(int index){
  if(!index){ return a; }
  else{ return b; }
}
/* -------------------------------------------------------------------------- */
void fillEdgeScoreboard(std::ostream & os, char fill){
  os << std::setfill(fill) << std::setw(48);
  os << "" << std::endl;
}
std::string constructLine(MatchPlayer &p){
  std::string serve = p.isServer() ? "   *   " : "       ";
  std::string name = p.getName();
  std::string points = std::to_string(p.getPoints());
  std::string games = std::to_string(p.getGames());
  std::string sets = std::to_string(p.getSets());
  name.resize(14, ' ');
  points.resize(8, ' ');
  games.resize(7, ' ');
  sets.resize(6, ' ');
  return "|" + serve + "|" + name + "|" + sets + "|" + games + "|" + points + "|";
}
std::ostream& operator<<(std::ostream& os, Match& m){
  MatchPlayer a = m.getPlayer(0);
  MatchPlayer b = m.getPlayer(1);
  fillEdgeScoreboard(os, '~');
  os << "| Serve |     Name     | Sets | Games | Points |" << std::endl;
  fillEdgeScoreboard(os, '-');
  os << constructLine(a) << std::endl;
  fillEdgeScoreboard(os, '-');
  os << constructLine(b) << std::endl;
  fillEdgeScoreboard(os, '~');
  return os;
}
