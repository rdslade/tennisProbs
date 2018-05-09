#include <iostream>
#include <string>
#include "Match.h"
#include "Player.h"
#include "stats.h"

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

Match::Match() : a(MatchPlayer()), b(MatchPlayer()), serverNetP(0) {}
Match::Match(const MatchPlayer a_in, const MatchPlayer b_in)
  : a(a_in), b(b_in), serverNetP(0) {}
