#include <iostream>
#include <string>
#include "Match.h"
#include "Player.h"
#include "stats.h"
#include <iomanip>
#include <cmath>

const std::string TENNISPOINTS[5] = {"0", "15", "30", "40", "AD"};
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
void MatchPlayer::winPoint(){
  points++;
}
void MatchPlayer::winGame(){
  games++;
}
void MatchPlayer::winSet(){
  sets++;
}
void MatchPlayer::resetGame(){
  points = 0;
}
void MatchPlayer::resetSet(){
  games = 0;
  resetGame();
}
void MatchPlayer::setDuece(){
  points = 3;
}
/* -------------------------------------------------------------------------- */
Match::Match() : a(MatchPlayer()), b(MatchPlayer()), serverNetP(0) {}
Match::Match(const MatchPlayer a_in, const MatchPlayer b_in)
  : a(a_in), b(b_in), serverNetP(0) {}
MatchPlayer & Match::getPlayer(int index){
  if(!index){ return a; }
  else{ return b; }
}
void Match::resetGame(){
  a.resetGame();
  b.resetGame();
  if(a.isServer()){
    a.setServe(false);
    b.setServe(true);
  }
  else{
    a.setServe(true);
    b.setServe(false);
  }
  setServerNetP();
}
void Match::resetSet(){
  a.resetSet();
  b.resetSet();
}
void Match::setDuece(){
  a.setDuece();
  b.setDuece();
}
void Match::setServerNetP(){
  const MatchPlayer &server = (a.isServer()) ? a : b;
  const MatchPlayer &returner = (a.isServer()) ? b : a;
  serverNetP = server.getServePercentage() / (server.getServePercentage() + returner.getReturnPercentage());
}
double Match::getServerGameProb(const MatchPlayer &server, const MatchPlayer &returner) const{
  double returnNetP = 1 - serverNetP;
  int serverPoints = server.getPoints();
  int returnerPoints = returner.getPoints();
  if(serverPoints == 4 && returnerPoints == 3){
    serverPoints = 3;
    returnerPoints = 2;
  }
  else if(returnerPoints == 4 && serverPoints == 3){
    returnerPoints = 3;
    serverPoints = 2;
  }
  double sum = 0;
  for(int n = 0; n < 3 - returnerPoints; n++){
      sum += pow(serverNetP, 4 - serverPoints) *
      pow(returnNetP, n) *
      nchoosek(3 - serverPoints + n, n);
  }
  sum += pow(serverNetP, 2) / (1 - 2*serverNetP*returnNetP) *
          nchoosek(6 - returnerPoints - serverPoints, 3 - returnerPoints) *
          pow(serverNetP, 3 - serverPoints) *
          pow(returnNetP, 3 - returnerPoints);
  return sum;
}
double Match::getCurrentGameProb() const{
  const MatchPlayer &server = (a.isServer()) ? a : b;
  const MatchPlayer &returner = (a.isServer()) ? b : a;
  return getServerGameProb(server, returner);
}
/* -------------------------------------------------------------------------- */
void fillEdgeScoreboard(std::ostream & os, char fill){
  os << std::setfill(fill) << std::setw(55);
  os << "" << std::endl;
}
std::string constructLine(MatchPlayer &p, double probability){
  std::string serve = p.isServer() ? "   *   " : "       ";
  std::string name = p.getName();
  std::string points = TENNISPOINTS[p.getPoints()];
  std::string games = std::to_string(p.getGames());
  std::string sets = std::to_string(p.getSets());
  std::string prob = (p.isServer()) ? std::to_string(probability) : std::to_string(1 - probability);
  name.resize(14, ' ');
  points.resize(8, ' ');
  games.resize(7, ' ');
  sets.resize(6, ' ');
  prob.resize(6, ' ');
  return "|" + serve + "|" + name + "|" + sets + "|" + games + "|" + points + "|" + prob + "|";
}
std::ostream& operator<<(std::ostream& os, Match& m){
  MatchPlayer a = m.getPlayer(0);
  MatchPlayer b = m.getPlayer(1);
  fillEdgeScoreboard(os, '~');
  os << "| Serve |     Name     | Sets | Games | Points | Prob |" << std::endl;
  fillEdgeScoreboard(os, '-');
  os << constructLine(a, m.getCurrentGameProb()) << std::endl;
  fillEdgeScoreboard(os, '-');
  os << constructLine(b, m.getCurrentGameProb()) << std::endl;
  fillEdgeScoreboard(os, '~');
  return os;
}
